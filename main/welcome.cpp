//
// Created by Poncoe on 06/05/19.
//

// ASCII GENERATOR by patorjk
// http://patorjk.com/software/taag/#p=display&f=Graffiti&t=Type%20Something%20

#include <iostream>
#include "welcome.h"

using namespace std;

//==================================== MENU TIDAK ADA =======================================

int menuSalah() {

    std::cout << R"(
  ______ _____  _____   ____  _____  _
 |  ____|  __ \|  __ \ / __ \|  __ \| |
 | |__  | |__) | |__) | |  | | |__) | |
 |  __| |  _  /|  _  /| |  | |  _  /| |
 | |____| | \ \| | \ \| |__| | | \ \|_|
 |______|_|  \_\_|  \_\\____/|_|  \_(_)

                                       )" << '\n';



    std::cout << R"(
Angka Menu yang anda Masukan Tidak Ada, Program Otomatis Keluar, Sampai Jumpa!
)" << '\n';

}

//==================================== KELUAR DARI APLIKASI =======================================

int goodByeFromOtherSide() {

    //Tulisan HoomanMeonk

    std::cout << R"(
  _    _                                   __  __                  _    _
 | |  | |                                 |  \/  |                | |  | |
 | |__| | ___   ___  _ __ ___   __ _ _ __ | \  / | ___  ___  _ __ | | _| |
 |  __  |/ _ \ / _ \| '_ ` _ \ / _` | '_ \| |\/| |/ _ \/ _ \| '_ \| |/ / |
 | |  | | (_) | (_) | | | | | | (_| | | | | |  | |  __/ (_) | | | |   <|_|
 |_|  |_|\___/ \___/|_| |_| |_|\__,_|_| |_|_|  |_|\___|\___/|_| |_|_|\_(_)


)" << '\n';


    std::cout << R"(
Anda Telah Memilih Menu "Keluar dari Aplikasi" Terimakasih dan sampai ketemu lagi.
)" << '\n';

}

//==================================== WELCOME DIALOG INDONESIA =======================================

int welcomeIndo() {

    //Tulisan HoomanMeonk

    std::cout << R"(
  _    _                                   __  __                  _    _
 | |  | |                                 |  \/  |                | |  | |
 | |__| | ___   ___  _ __ ___   __ _ _ __ | \  / | ___  ___  _ __ | | _| |
 |  __  |/ _ \ / _ \| '_ ` _ \ / _` | '_ \| |\/| |/ _ \/ _ \| '_ \| |/ / |
 | |  | | (_) | (_) | | | | | | (_| | | | | |  | |  __/ (_) | | | |   <|_|
 |_|  |_|\___/ \___/|_| |_| |_|\__,_|_| |_|_|  |_|\___|\___/|_| |_|_|\_(_)


)" << '\n';

    //Tulisan Kotak nya

    std::cout << R"(
|========================================================================|
|Selamat Datang Di Program Hooman Meonk.                                 |
|                                                                        |
|By Arief Wardhana (1301173708) Teknik Informatika                       |
|Telkom University 2019.                                                 |
|========================================================================|
)" << '\n';

}
