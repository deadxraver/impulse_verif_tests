Для успешной работы примера, нужно запускать скрипт из окружения Ubuntu версии не ниже 20 (лучше 22)

Тестовый набор включает ядро Linux, uboot, OpenSBI из дерева sc-dt и дополнительного файла для запуска bad_app.elf
Для запуска теста выполняется следующая последовательность:

Запустить sshd (для доступа из образа Линукса к Вашему хосту):
service sshd start

Запускаем скрипт для загрузки Линукс:
./start_linux_qemu.sh

Он останавливается после загрузки uboot.
Вывод программы:

Err:   serial@10000
Model: Syntacore SCR7 SDK board
Net:   AXI EMAC: ffffffff040000, phyaddr 3, interface sgmii
eth0: ethernet@40000
=>

необходимо набрать команду boot и нажать <Enter>, загрузка ядра продолжится.

Для аутентификации нужно ввести логин/пароль root/root

После этого выполняется последовательность команд (full_path_to_app заменяется на полный путь к файлу на хосте,
user - на имя пользователя):
udhcpc -i eth0 ; scp user@10.0.2.2:full_path_to_app/bad_app.elf ./

Ожидаемый вывод программ:
udhcpc: started, v1.36.1
udhcpc: broadcasting discover
udhcpc: broadcasting select for 10.0.2.15, server 10.0.2.2
udhcpc: lease of 10.0.2.15 obtained from 10.0.2.2, lease time 86400
deleting routers
adding dns 10.0.2.3

Host '10.0.2.2' is not in the trusted hosts file.
(ssh-ed25519 fingerprint SHA256:y/dRZSt0Kr3+jRBqhuJ7ZB4VwlXSg/gKfZSZcCLYnKs)
Do you want to continue connecting? (y/n) y
user@10.0.2.2's password: 

На запрос "Do you want to continue connecting? (y/n)" нужно ответить Y и нажать <Enter>
В поле ввода пароля пользователя ввести пароль.

При копировании файла должно вывестись сообщение об успешном копировании:
bad_app.elf                                   100% 6128     6.0KB/s   00:00

После этого выполнить запуск программы:
./bad_app.elf

Выход из QEMU производится по комбинации клавиш
Ctrl + A -> c -> q

=====================================================
Запуск с отладчиком (запускаются в разных консолях):
Сначала (консоль 1):
# ./start_gdb_server.sh
Следом (консоль 2):
# ./start_linux_qemu_gdb.sh
Далее, см. выше
Отладка ведётся в консоли 1.
=====================================================

Вопросы/задания:
1. Какое сообщение должна была вывести программа
2. Исправить программу в двоичном виде, чтобы она заработала верно и запустить её в Линуксе
