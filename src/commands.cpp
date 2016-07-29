#include "commands.h"

Commands::Commands(QObject *parent) : QObject(parent)
{

}

int Commands::switchWorld(QString password,QString alias, QString mountpoint){
   int open = system("bash -c \" echo 'crypt' | sudo cryptsetup luksOpen /dev/mmcblk1p2 crypt \"");
   int mount = system("sudo mount /dev/mapper/crypt /home");
}
