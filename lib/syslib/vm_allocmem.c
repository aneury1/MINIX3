
#include "syslib.h"

#include <minix/vm.h>

/*===========================================================================*
 *                                vm_allocmem				     *
 *===========================================================================*/
PUBLIC int vm_allocmem(phys_clicks clicks, phys_clicks *retmembase)
{
    message m;
    int result;

    m.VMAM_CLICKS = clicks;
    result = _taskcall(VM_PROC_NR, VM_ALLOCMEM, &m);
    if(result == OK)
	    *retmembase = m.VMAM_MEMBASE;

    return result;
}
