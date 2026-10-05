
//sudo dnf install pciutils-devel
#include <pci/pci.h>
#include <iostream>
#include <string>

using namespace std;

string gpu(){

    string result = "unknown";
    
    pci_access* pacc = pci_alloc();
    pci_init(pacc);
    pci_scan_bus(pacc);

        for (pci_dev* dev = pacc->devices; dev; dev = dev->next) {
        pci_fill_info(dev, PCI_FILL_IDENT | PCI_FILL_CLASS);

        // class 0x03xx = display controller
        if ((dev->device_class >> 8) == 0x03) {
            char buf[256];
            pci_lookup_name(pacc, buf, sizeof(buf),
                            PCI_LOOKUP_VENDOR | PCI_LOOKUP_DEVICE,
                            dev->vendor_id, dev->device_id);
            result = buf;
            break;
        }
    }

    pci_cleanup(pacc);
    return result;

}