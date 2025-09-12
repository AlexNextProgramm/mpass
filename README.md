# Mpass

This is an open source program. For Linux systems.
The program stores passwords on the machine in encrypted form. Ability to add delete passwords. In order to view all passwords in the future, it is planned to connect it to a remote service where they can be stored.

Download

`wget https://raw.githubusercontent.com/AlexNextProgramm/mpass/refs/heads/main/data/mpass_v1.deb`

Install

`sudo dpkg -i \~/mpass_v1.deb`

### Start

start programm `mpass`

*You will need to enter your encryption key, you can come up with any key, but then use only it, since it decrypts passwords for you.*

`help` or `-h` or `-help`

### Add new Password

`add my@gmail.com  password111`

### Read

`my@gmail.com`

or

`get my@gmail.com`

result *Ваш пароль: password111*
