#ifndef DIFF_INTERFACE_H
#define DIFF_INTERFACE_H

#include "mmu.h"
#include "sim.h"
#include "../../include/common.h"
#include <difftest-def.h>

#include <vector>

// 定义数据结构和变量
static std::vector<std::pair<reg_t, abstract_device_t*>> difftest_plugin_devices;
static std::vector<std::string> difftest_htif_args;
static std::vector<std::pair<reg_t, mem_t*>> difftest_mem(1, std::make_pair(reg_t(DRAM_BASE), new mem_t(CONFIG_MSIZE)));
static std::vector<int> difftest_hartids;
static debug_module_config_t difftest_dm_config = {
  .progbufsize = 2,
  .max_sba_data_width = 0,
  .require_authentication = false,
  .abstract_rti = 0,
  .support_hasel = true,
  .support_abstract_csr_access = true,
  .support_abstract_fpr_access = true,
  .support_haltgroups = true,
  .support_impebreak = true
};

// 函数声明
extern "C" {

    // 初始化函数
    void difftest_init(int port);

    // 内存拷贝函数
    void difftest_memcpy(paddr_t addr, void* buf, size_t n, bool direction);

    // 寄存器拷贝函数
    void difftest_regcpy(void* dut, bool direction);

    // 执行函数
    void difftest_exec(uint64_t n);

    // 触发中断函数
    void difftest_raise_intr(uint64_t NO);

}

#endif // DIFF_INTERFACE_H
