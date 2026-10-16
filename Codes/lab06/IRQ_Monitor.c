//IRQ_Monitor.c	

// Interrupt Monitor; Disable and enable interrupts in linux
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/interrupt.h>
#include <linux/delay.h>

// Create a flag for the status of interrupts
static unsigned long flags

// module loading function
static int __init monitor_init(void){
    printk(KERN_INFO "Interrupts disabled for 5 seconds. Press some keys \n");

    // save status and disable interrupts 
    local_irq_save(flags);   

    // Busy waiting
    mdelay(5000);
    
    // Enable interrupts again 
    local_irq_restore(flags); }
    printk(KERN_INFO "Interrupts enabled again\n");
    return 0;   }

// module unloading function
static void __exit monitor_exit(void) {
        printk(KERN_INFO "Module unloaded.\n");  }

module_init(monitor_init);
module_exit(monitor_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("OSLaboratory of Urmia University");
MODULE_DESCRIPTION("Interrupt Monitor");
