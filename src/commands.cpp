#include "commands.h"

Commands::Commands(QObject *parent) : QObject(parent)
{

}

int Commands::switchWorld(QString password,QString alias, QString mountpoint){
   int open = system("bash -c \" echo 'crypt' | sudo cryptsetup luksOpen /dev/mmcblk1p2 crypt \"");
   int mount = system("sudo mount /dev/mapper/crypt /home");
   int restart = system("systemctl --user restart ambienced");
}

bool Commands::isInSafeMode(){
    int inSafeMode = system("bash -c \"(ls /dev/mapper/ | grep crypt) && (mount | grep /dev/mapper/crypt)\"");
    return inSafeMode == 0;
}


bool Commands::hasFlash(){
    int hasFlash = system("bash -c \"ls /dev/ | grep mmcblk1\"");
    return hasFlash == 0;
}
