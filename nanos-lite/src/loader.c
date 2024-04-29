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

static uintptr_t loader(PCB *pcb, const char *filename) {
	int fd = fs_open(filename, 0, 0);
	assert(fd >= 0);

	Elf_Ehdr ehdr;
	fs_lseek(fd, 0, SEEK_SET);
	fs_read(fd, &ehdr, sizeof(Elf_Ehdr));
	// assert(bytes_read == sizeof(Elf_Ehdr));
	// ramdisk_read(&ehdr, 0, sizeof(Elf_Ehdr));
	// check valid elf
	assert((*(uint32_t*)ehdr.e_ident == 0x464c457f));

	Elf_Phdr phdr[ehdr.e_phnum];
	fs_lseek(fd, ehdr.e_phoff, SEEK_SET);
	fs_read(fd, phdr, sizeof(Elf_Phdr) * ehdr.e_phnum);
	// assert(bytes_read == sizeof(Elf_Phdr) * ehdr.e_phnum);
	// ramdisk_read(phdr, ehdr.e_phoff, sizeof(Elf_Phdr) * ehdr.e_phnum);

	Log("[Nanos-lite] Loading Segments...");
	for (int i = 0; i < ehdr.e_phnum; i++) {
		if (phdr[i].p_type == PT_LOAD) {
			fs_lseek(fd, phdr[i].p_offset, SEEK_SET);
			fs_read(fd, (void*)phdr[i].p_vaddr, phdr[i].p_memsz);
			// ramdisk_read((void*)phdr[i].p_vaddr, phdr[i].p_offset, phdr[i].p_memsz);
			// set .bss with zeros
			memset((void*)(phdr[i].p_vaddr + phdr[i].p_filesz), 0, phdr[i].p_memsz - phdr[i].p_filesz);
		}
	}
	return ehdr.e_entry;
}

uintptr_t naive_uload(PCB* pcb, const char* filename) {
	Log(ANSI_BOLD_YELLOW "SFS: Loading file [%s]...", filename);
	uintptr_t entry = loader(pcb, filename);
	// Log("Jump to entry = %p", entry);
	return entry;
}

