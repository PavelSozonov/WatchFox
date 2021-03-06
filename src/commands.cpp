#include "commands.h"

Commands::Commands(QObject *parent) : QObject(parent)
{

}

int Commands::switchWorld(QString password,QString alias, QString devicePath){
    const char* openCommand = QString("bash -c \" echo '%1' | sudo cryptsetup luksOpen %2 crypt \"")
            .arg(password,devicePath).toStdString().c_str();
    int open = system(openCommand);
//   int open = system("bash -c \" echo 'crypt' | sudo cryptsetup luksOpen /dev/mmcblk1p2 crypt \"");
   int mount = system("sudo mount /dev/mapper/crypt /home");
   int restart = system("systemctl --user restart ambienced");
   return 0;
}

bool Commands::isInSafeMode(){
    int inSafeMode = system("bash -c \"(ls /dev/mapper/ | grep crypt) && (mount | grep /dev/mapper/crypt)\"");
    return inSafeMode == 0;
}


bool Commands::hasFlash(){
    int hasFlash = system("bash -c \"ls /dev/ | grep mmcblk1\"");
    return hasFlash == 0;
}

int Commands::createCryptHome(QString password,QString devicePath){
    system("mkdir /tmp/crypt");
    const char* openCommand = QString("bash -c \" echo '%1' | sudo cryptsetup luksOpen %2 crypt \"")
            .arg(password,devicePath).toStdString().c_str();
    const char* mountCommand =  QString("sudo mount %1 /tmp/crypt").arg(devicePath).toStdString().c_str();
    system(openCommand);
    system(mountCommand);
    system("cp -a /home/nemo /tmp/crypt/nemo");
    system("umount -l /tmp/crypt");
    system("sudo cryptsetup luksClose crypt");
    return 0;
}


