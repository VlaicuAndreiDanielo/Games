#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <ctime>
#include <sstream>
#include <vector>
#include <cstdlib>

void Desen(int literegresite) {
    switch (literegresite) {
    case 0:
        std::cout << "_________    " << std::endl;
        std::cout << "|       |    " << std::endl;
        std::cout << "|            " << std::endl;
        std::cout << "|            " << std::endl;
        std::cout << "|            " << std::endl;
        std::cout << "|            " << std::endl;
        std::cout << "|            " << std::endl;
        break;
    case 1:
        std::cout << "_________    " << std::endl;
        std::cout << "|       |    " << std::endl;
        std::cout << "|       O    " << std::endl;
        std::cout << "|            " << std::endl;
        std::cout << "|            " << std::endl;
        std::cout << "|            " << std::endl;
        std::cout << "|            " << std::endl;
        break;
    case 2:
        std::cout << "_________    " << std::endl;
        std::cout << "|       |    " << std::endl;
        std::cout << "|       O    " << std::endl;
        std::cout << "|       |    " << std::endl;
        std::cout << "|       |    " << std::endl;
        std::cout << "|            " << std::endl;
        std::cout << "|            " << std::endl;
        break;
    case 3:
        std::cout << "_________    " << std::endl;
        std::cout << "|       |    " << std::endl;
        std::cout << "|       O    " << std::endl;
        std::cout << "|      ||    " << std::endl;
        std::cout << "|       |    " << std::endl;
        std::cout << "|            " << std::endl;
        std::cout << "|            " << std::endl;
        break;
    case 4:
        std::cout << "_________    " << std::endl;
        std::cout << "|       |    " << std::endl;
        std::cout << "|       O    " << std::endl;
        std::cout << "|      |||   " << std::endl;
        std::cout << "|       |    " << std::endl;
        std::cout << "|            " << std::endl;
        std::cout << "|            " << std::endl;
        break;
    case 5:
        std::cout << "_________    " << std::endl;
        std::cout << "|       |    " << std::endl;
        std::cout << "|       O    " << std::endl;
        std::cout << "|      |||   " << std::endl;
        std::cout << "|       |    " << std::endl;
        std::cout << "|      /     " << std::endl;
        std::cout << "|            " << std::endl;
        break;
    case 6:
        std::cout << "_________    " << std::endl;
        std::cout << "|       |    " << std::endl;
        std::cout << "|       O    " << std::endl;
        std::cout << "|      |||   " << std::endl;
        std::cout << "|       |    " << std::endl;
        std::cout << "|      / \\  " << std::endl;
        std::cout << "|            " << std::endl;
        std::cout << std::endl;
        std::cout << "  Game over! " << std::endl;
        break;
    }
}
void AfisareLitere(std::string sir)
{
    for (int i = 0; i < sir.size(); i++)
    {
        std::cout << sir[i];
    }
}
void Litera(char& literaghicita, std::string &litcit) 
{
    std::cout << std::endl << "Introduce o litera: ";
    std::cin >> literaghicita;
    literaghicita = toupper(literaghicita);
    if (litcit.find(literaghicita) != std::string::npos)
    {
        std::cout << std::endl << "Litera a fost citita deja" << std::endl;
        Litera(literaghicita, litcit);
    }
    else
    {
        litcit.push_back(literaghicita);
        litcit.push_back(' ');
    }

}
void Inlocuire(std::string cuvant, std::string &afis, char literaghicita) {
    for (int i = 0; i < cuvant.size(); i++)
    {
        if (cuvant[i] == literaghicita)
            afis[i] = literaghicita;
    }
    AfisareLitere(afis);
    system("CLS");
}
void Greseli(char& literaghicita, std::string &gresite) {
    gresite.push_back(literaghicita);
    gresite.push_back(' ');
}
void Corecte(char& literaghicita, std::string &corect) {
    corect.push_back(literaghicita);
    corect.push_back(' '); 
}
void AlegereCuvant(int Nivel, std::string& afis,const std::vector<std::string>& NIV1, const std::vector<std::string>& NIV2, const std::vector<std::string>& NIV3, 
const std::vector<std::string>& NIV4, const std::vector<std::string>& NIV5, std::string &cuvant )
{
    int cuvantRandom;
    int x;
    switch (Nivel) {
    case 1:
        srand(time(nullptr));
        cuvantRandom = rand() % (NIV1.size());
        cuvant = NIV1[cuvantRandom];
        x = cuvant.size();
        while (x > 0)
        {
            std::cout << "_";
            afis += "_";
            x--;
        }
        break;
    case 2:
        srand(time(nullptr));
        cuvantRandom = rand() % (NIV2.size());
        cuvant = NIV2[cuvantRandom];
        x = cuvant.size();
        while (x > 0)
        {
            std::cout << "_";
            afis += "_";
            x--;
        }
        break;
    case 3:
        srand(time(nullptr));
        cuvantRandom = rand() % (NIV3.size());
        cuvant = NIV3[cuvantRandom];
        x = cuvant.size();
        while (x > 0)
        {
            std::cout << "_";
            afis += "_";
            x--;
        }
        break;
    case 4:
        srand(time(nullptr));
        cuvantRandom = rand() % (NIV4.size());
        cuvant = NIV4[cuvantRandom];
        x = cuvant.size();
        while (x > 0)
        {
            std::cout << "_";
            afis += "_";
            x--;
        }
        break;
    case 5:
        srand(time(nullptr));
        cuvantRandom = rand() % (NIV5.size());
        cuvant = NIV5[cuvantRandom];
        x = cuvant.size();
        while (x > 0)
        {
            std::cout << "_";
            afis += "_";
            x--;
        }
        break;
    }

}
// Nivelul 1 are cuvinte de 3-5 litere
void CitireNivel1(std::vector<std::string> &Nivel1)
{
    std::ifstream fisier("Nivel1.txt");
    std::string linie;
    while (std::getline(fisier, linie))
    {
        std::istringstream linie_stream(linie);
        std::string cuvant;
        while (linie_stream >> cuvant)
        {
            Nivel1.push_back(cuvant);
        }
    }

    fisier.close();
}
// Nivelul 2 are cuvinte de 6-8 litere
void CitireNivel2(std::vector<std::string> &Nivel2)
{
    std::ifstream fisier("Nivel2.txt");
    std::string linie;
    while (std::getline(fisier, linie))
    {
        std::istringstream linie_stream(linie);
        std::string cuvant;
        while (linie_stream >> cuvant)
        {
           Nivel2.push_back(cuvant);
        }
    }

    fisier.close();
}
// Nivelul 3 are cuvinte de 9-11 litere
void CitireNivel3(std::vector<std::string> &Nivel3)
{
    std::ifstream fisier("Nivel3.txt");
    std::string linie;
    while (std::getline(fisier, linie))
    {
        std::istringstream linie_stream(linie);
        std::string cuvant;
        while (linie_stream >> cuvant)
        {
            Nivel3.push_back(cuvant);
        }
    }
    fisier.close();
}
// Nivelul 4 are cuvinte de 12-14 litere
void CitireNivel4(std::vector<std::string> &Nivel4)
{
    std::ifstream fisier("Nivel4.txt");
    std::string linie;
    while (std::getline(fisier, linie))
    {
        std::istringstream linie_stream(linie);
        std::string cuvant;
        while (linie_stream >> cuvant)
        {
            Nivel4.push_back(cuvant);
        }
    }

    fisier.close();
}
// Nivelul 5 are cuvinte cu mai mult de 15 litere
void CitireNivel5(std::vector<std::string> &Nivel5)
{
    std::ifstream fisier("Nivel5.txt");
    std::string linie;
    while (std::getline(fisier, linie)) 
    { 
        std::istringstream linie_stream(linie);
        std::string cuvant;
        while (linie_stream >> cuvant) 
        { 
            Nivel5.push_back(cuvant); 
        }
    }
    fisier.close();
}
/*void CitireNivel(const std::string& filename, std::vector<std::string>& Nivel) {
    std::ifstream fisier(filename);
    std::string linie;
     while (std::getline(fisier, linie)) 
     {
       std::istringstream linie_stream(linie);
        std::string cuvant;
       while (linie_stream >> cuvant) 
       {
            Nivel.push_back(cuvant);
       }
     }
    fisier.close();
}
*/
void Procesare(bool &Castig, int &gres, const int Max_gres, std::string cuvant, char &literaghicita, std::string &afis, std::string& corect,
std::string &gresite, std::string &litcit)
{
    do
    {
        if (!Castig)
        {
            if (cuvant.find(literaghicita) != std::string::npos)
            {
                Inlocuire(cuvant, afis, literaghicita); AfisareLitere(afis); std::cout << std::endl;
                Desen(gres); Corecte(literaghicita,corect); std::cout << std::endl;
                std::cout << std::endl << "Cuvantul are " << cuvant.size() << " litere" << std::endl;
                std::cout << "Vieti ramase:" << Max_gres - gres << std::endl;
                std::cout << "Literele folosite sunt: "; AfisareLitere(litcit); std::cout << std::endl;
                std::cout << "Literele corecte sunt: "; AfisareLitere(corect); std::cout << std::endl;
                std::cout << "Literele gresite sunt: "; AfisareLitere(gresite); std::cout << std::endl;
                if (cuvant==afis)
                {
                    Castig = 1;
                    break;
                }
                Litera(literaghicita,litcit); std::cout << std::endl;
            }

            else

            {
                gres++;
                system("CLS");
                AfisareLitere(afis); std::cout << std::endl;
                Desen(gres); Greseli(literaghicita, gresite); std::cout << std::endl;
                std::cout << std::endl << "Cuvantul are " << cuvant.size() << " litere" << std::endl;
                std::cout << "Vieti ramase:" << Max_gres - gres << std::endl;
                std::cout << "Literele folosite sunt: "; AfisareLitere(litcit); std::cout << std::endl;
                std::cout << "Literele corecte sunt: "; AfisareLitere(corect); std::cout << std::endl;
                std::cout << "Literele gresite sunt: "; AfisareLitere(gresite); std::cout << std::endl;
                Litera(literaghicita, litcit); std::cout << std::endl;
            }
        }
    } while ((gres < Max_gres - 1) && (!Castig));
}
void VerificareCastig(bool Castig,const int Max_gres, int gres, std::string cuvant)
{
    if (Castig==true)
    {
        system("CLS");
        AfisareLitere(cuvant); std::cout << std::endl;
        std::cout << "Ai castigat!";
        int score = 100 * (Max_gres - gres);
        std::cout << std::endl << "Scorul este de: " << score;
        std::cout << std::endl;
    }
    else
    {
        system("ClS");
        AfisareLitere(cuvant); std::cout << std::endl;
        Desen(6);
        std::cout << std::endl;
    }
}
int main()
{
    const int Max_gres = 6;
    int Nivel;
    std::cout << "Nivelul ales:";
    std::cin >> Nivel;
    int gres = 0;
    bool Castig = false;

    if (Nivel >= 5)
    {
        std::cout << "Mult noroc, o sa ai nevoie!=)" << std::endl;
        Nivel = 5;
    }
    std::string cuvant; std::string litcit; std::string afis;
    int poz =0, k=0, h=0; char literaghicita;
    std::string corect, gresite;
    std::vector<std::string> Nivel1, Nivel2, Nivel3, Nivel4, Nivel5;
    /*CitireNivel("Nivel1.txt", Nivel1); CitireNivel("Nivel2.txt", Nivel2); CitireNivel("Nivel3.txt", Nivel3); CitireNivel("Nivel4.txt", Nivel4); CitireNivel("Nivel5.txt", Nivel5); */
    CitireNivel1(Nivel1); CitireNivel2(Nivel2); CitireNivel3(Nivel3); CitireNivel4(Nivel4); CitireNivel5(Nivel5);
    AlegereCuvant(Nivel, afis, Nivel1, Nivel2, Nivel3, Nivel4, Nivel5, cuvant);

    std::cout << std::endl; Desen(gres); std::cout << std::endl;
    std::cout << std::endl << "Cuvantul are " << cuvant.size() << " litere" << std::endl;
    Litera(literaghicita,litcit); std::cout << std::endl;
    Procesare(Castig, gres,  Max_gres, cuvant, literaghicita, afis, corect, gresite, litcit);
    VerificareCastig(Castig, Max_gres, gres, cuvant);
    return 0;
}