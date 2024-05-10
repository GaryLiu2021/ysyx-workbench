#include <proc.h>
#include <elf.h>
#include <fs.h>

#ifdef __LP64__
# define Elf_Ehdr Elf64_Ehdr
# define Elf_Phdr Elf64_Phdr
#else
# define Elf_Ehdr Elf32_Ehdr
# define Elf_Phdr Elf32_Phdr
#endif

static uintptr_t loader(PCB* pcb, const char* filename) {
    // In case that filename does not exist(eg. execvp).
    int fd = fs_open(filename, 0, 0);
	if (fd == -1)
		return (uintptr_t)NULL;

    // Fetch the elf header
    Elf_Ehdr ehdr;
	fs_lseek(fd, 0, SEEK_SET);
	fs_read(fd, &ehdr, sizeof(Elf_Ehdr));
	// assert(bytes_read == sizeof(Elf_Ehdr));
	// ramdisk_read(&ehdr, 0, sizeof(Elf_Ehdr));
	// check valid elf
	assert((*(uint32_t*)ehdr.e_ident == 0x464c457f));

    // Fetch the program headers
    Elf_Phdr phdr[ehdr.e_phnum];
	fs_lseek(fd, ehdr.e_phoff, SEEK_SET);
	fs_read(fd, phdr, sizeof(Elf_Phdr) * ehdr.e_phnum);
	// assert(bytes_read == sizeof(Elf_Phdr) * ehdr.e_phnum);
	// ramdisk_read(phdr, ehdr.e_phoff, sizeof(Elf_Phdr) * ehdr.e_phnum);

    // Load segments with flag PT_LOAD
    for (int i = 0; i < ehdr.e_phnum; i++) {
        if (phdr[i].p_type == PT_LOAD) {
			fs_lseek(fd, phdr[i].p_offset, SEEK_SET);
			// printf("Start %p, End %p\n", phdr[i].p_vaddr, phdr[i].p_vaddr + phdr[i].p_memsz);
			if (!PG_OFF(phdr[i].p_vaddr)) {
				int nr_page = (phdr[i].p_memsz + PGSIZE - 1) / PGSIZE;
				char* end = new_page(nr_page);
				char* start = end - nr_page * PGSIZE;
				memset(start, 0, nr_page * PGSIZE);
				fs_read(fd, start, phdr[i].p_filesz);
				for (int pg = 0;pg < nr_page * PGSIZE;pg += PGSIZE)
					map(&pcb->as, (void*)(phdr[i].p_vaddr + pg), (void*)(start + pg), PROT_RWX);
			}
			else {
				int nr_page = (phdr[i].p_memsz + PGSIZE - 1) / PGSIZE + (PG_OFF(phdr[i].p_vaddr) + PG_OFF(phdr[i].p_memsz) > PGSIZE);
				char* end = new_page(nr_page);
				char* start = end - nr_page * PGSIZE;
				memset(start, 0, nr_page * PGSIZE);
				fs_read(fd, start + PG_OFF(phdr[i].p_vaddr), phdr[i].p_filesz);
				for (int pg = 0;pg < nr_page * PGSIZE;pg += PGSIZE)
					map(&pcb->as, (void*)(PG_NUM(phdr[i].p_vaddr) + pg), (void*)(start + pg), PROT_RWX);
			}
			pcb->max_brk = phdr[i].p_vaddr + phdr[i].p_memsz - 1;
			printf("BRK now %p\n", pcb->max_brk);
		}
	}

	fs_close(fd);
	return ehdr.e_entry;
}

uintptr_t naive_uload(PCB* pcb, const char* filename) {
	Log(ANSI_BOLD_YELLOW "SFS: Loading file [%s]...", filename);
	uintptr_t entry = loader(pcb, filename);
	// Log("Jump to entry = %p", entry);
	return entry;
}

