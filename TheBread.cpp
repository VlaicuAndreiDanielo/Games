#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <ctime>
#include <cstdlib>

void Reguli()
{
    std::cout << "REGULILE JOCULUI PAINICA" << std::endl;
    std::cout << "----------------------------" << std::endl;
    std::cout << "Jocul incepe dupa ce jucatorul alege cine incepe, el sau calculatorul." << std::endl;
    std::cout << "Jucatorul sau calculatorul in functie de alegerea anterioara va selecta un numar de la 1 la 10" << std::endl;
    std::cout << "iar celalalt va incerca sa ghiceasca numaru. Daca l-a gicit primeste punctul. Numarul cu 3 puncte" << std::endl;
    std::cout << "devine o painica. Castigatorul este cel ce obtine primul 9 painici." << std::endl;
    std::cout << "DISTRACTIE PLACUTA!" << std::endl;
} 
void Afisare(std::array<int, 10> Jucator, std::array<int, 10> Calculator)
{
    std::cout<<"PAINICI JUCATOR" << std::endl;
    for (int i = 0; i < 10; i++)
    {
        if (Jucator[i] == 3)
            std::cout << "Painica(" << i + 1 << ")" << std::endl;
        else
            std::cout << "Numar:" << i + 1 << "=" << Jucator[i] << std::endl;
    }
    std::cout << std::endl;
    std::cout << "--------------------------------------";
    std::cout << std::endl;

    std::cout << "PAINICI CALCULATOR" << std::endl;
    for (int i = 0; i < 10 ; i++)
    {
        if (Calculator[i] == 3)
            std::cout << "Painica(" << i + 1 << ")" << std::endl;
        else
            std::cout << "Numar:" << i + 1 << "=" << Calculator[i] << std::endl;
    }
    std::cout << std::endl;
}

void JucareJucator(std::array<int, 10>& Jucator, std::array<int, 10>& Calculator, int &NumarulJucatorului, int &NumarulCalculatorului, int& NrPainiciJucator, int& NrPainiciCalculator, int& pozjuc, int& pozcalc, std::array<int, 9>& PainiciJucator, std::array<int, 9>& PainiciCalculator, std::vector<int> &Numere);

void VerificareCastig(int NrPainiciJucator, int NrPainiciCalculator)
{
    if (NrPainiciJucator == 9 && NrPainiciCalculator < 9)
    {
        system("CLS");
        std::cout << "Ai castigat!" << std::endl;
        return;
    }
    if (NrPainiciCalculator == 9 && NrPainiciJucator < 9)
    {
        system("CLS");
        std::cout << "Ai pierdut! Calculatorul a castigat." << std::endl;
        return;
    }
}
void AlegereRandomCalculator(int& NumarulCalculatorului, std::array<int, 10> &Calculator, std::vector<int> &Numere)
{
    srand(time(nullptr));
    NumarulCalculatorului = rand() % (10) + 1;
    if (Calculator[NumarulCalculatorului - 1] == 3)
    {
        Numere.erase(std::remove(Numere.begin(), Numere.end(), NumarulCalculatorului - 1), Numere.end());
        if(!Numere.empty())
        AlegereRandomCalculator(NumarulCalculatorului, Calculator, Numere);
    }
}
void JucareCalculator(std::array<int, 10>& Jucator, std::array<int, 10>& Calculator, int NumarulJucatorului, int NumarulCalculatorului, int& NrPainiciJucator, int& NrPainiciCalculator, 
    int &pozjuc, int &pozcalc, std::array<int, 9>& PainiciJucator, std::array<int, 9>& PainiciCalculator, std::vector<int> &Numere)
{
    if (NrPainiciCalculator < 9)
    {   // VerificareCastig(NrPainiciJucator, NrPainiciCalculator); Daca nu folosesc if
        AlegereRandomCalculator(NumarulCalculatorului, Calculator, Numere);
        if (Calculator[NumarulCalculatorului - 1] == 3)
        {
            if (std::find(PainiciCalculator.begin(), PainiciCalculator.end(), NumarulCalculatorului) == PainiciCalculator.end())
            {
                NrPainiciCalculator++;
                PainiciCalculator[pozcalc] = NumarulCalculatorului; pozcalc++;
                VerificareCastig(NrPainiciJucator, NrPainiciCalculator);
                system("CLS"); Afisare(Jucator, Calculator);
                AlegereRandomCalculator(NumarulCalculatorului, Calculator, Numere);
                JucareCalculator(Jucator, Calculator, NumarulJucatorului, NumarulCalculatorului, NrPainiciJucator, NrPainiciCalculator, pozjuc, pozcalc, PainiciJucator, PainiciCalculator, Numere);
            }
            else
            {
                system("CLS"); Afisare(Jucator, Calculator);
                AlegereRandomCalculator(NumarulCalculatorului, Calculator, Numere);
                JucareCalculator(Jucator, Calculator, NumarulJucatorului, NumarulCalculatorului, NrPainiciJucator, NrPainiciCalculator, pozjuc, pozcalc, PainiciJucator, PainiciCalculator, Numere);
            }
            VerificareCastig(NrPainiciJucator, NrPainiciCalculator);
        }
        else
            if (Calculator[NumarulCalculatorului - 1] < 3 && NumarulCalculatorului >= 1 && NumarulCalculatorului <= 10)
            {
                std::cout << "Calculatorul a ales deja un numar. Incearca sa ghicesti pentru a castiga punctul." << std::endl;
                std::cout << "Alege-ti un numar de la 1 la 10" << std::endl;
                std::cin >> NumarulJucatorului;
                while (NumarulJucatorului > 10 || NumarulJucatorului < 1)
                {
                    std::cout << "Numarul este prea mare sau prea mic. Introduce-ti alt numar." << std::endl;
                    std::cin >> NumarulJucatorului;
                }
                if (NumarulCalculatorului != NumarulJucatorului)
                {
                    Calculator[NumarulCalculatorului - 1] = Calculator[NumarulCalculatorului - 1] + 1;
                    if (Calculator[NumarulCalculatorului - 1] == 3)
                    {
                        if (std::find(PainiciCalculator.begin(), PainiciCalculator.end(), NumarulCalculatorului) == PainiciCalculator.end())
                        {
                            NrPainiciCalculator++;
                            PainiciCalculator[pozcalc] = NumarulCalculatorului; pozcalc++;
                            VerificareCastig(NrPainiciJucator, NrPainiciCalculator);
                        }
                    }
                    VerificareCastig(NrPainiciJucator, NrPainiciCalculator);
                    system("CLS"); Afisare(Jucator, Calculator);
                    JucareCalculator(Jucator, Calculator, NumarulJucatorului, NumarulCalculatorului, NrPainiciJucator, NrPainiciCalculator, pozjuc, pozcalc, PainiciJucator, PainiciCalculator, Numere);
                }
                else
                {
                    std::cout << "Ai ghicit numarul calculatorului." << std::endl;
                    if (std::find(PainiciJucator.begin(), PainiciJucator.end(), NumarulJucatorului) == PainiciJucator.end())
                    {
                        Jucator[NumarulJucatorului - 1] = Jucator[NumarulJucatorului - 1] + 1;
                        system("CLS"); Afisare(Jucator, Calculator);
                        JucareJucator(Jucator, Calculator, NumarulJucatorului, NumarulCalculatorului, NrPainiciJucator, NrPainiciCalculator, pozjuc, pozcalc, PainiciJucator, PainiciCalculator, Numere);
                    }
                    VerificareCastig(NrPainiciJucator, NrPainiciCalculator);
                    JucareJucator(Jucator, Calculator, NumarulJucatorului, NumarulCalculatorului, NrPainiciJucator, NrPainiciCalculator, pozjuc, pozcalc, PainiciJucator, PainiciCalculator, Numere);
                }
            }
    }
    else
    {
        VerificareCastig(NrPainiciJucator, NrPainiciCalculator);
    }
}
void JucareJucator(std::array<int, 10> &Jucator, std::array<int, 10> &Calculator, int &NumarulJucatorului, int &NumarulCalculatorului, int &NrPainiciJucator, int &NrPainiciCalculator,
    int &pozjuc, int &pozcalc, std::array<int, 9> &PainiciJucator, std::array<int, 9> &PainiciCalculator, std::vector<int>& Numere)
{
    if (NrPainiciJucator < 9)
    {   // VerificareCastig(NrPainiciJucator, NrPainiciCalculator); Daca nu folosesc if
        std::cout << " Alege-ti un numar de la 1 la 10" << std::endl;
        std::cin >> NumarulJucatorului;
        if (NumarulJucatorului > 10 || NumarulJucatorului < 1)
        {
            std::cout << "Numarul este prea mare sau prea mic. Introduce-ti alt numar." << std::endl;
            JucareJucator(Jucator, Calculator, NumarulJucatorului, NumarulCalculatorului, NrPainiciJucator, NrPainiciCalculator, pozjuc, pozcalc, PainiciJucator, PainiciCalculator, Numere);
        }
        if (Jucator[NumarulJucatorului - 1] == 3)
        {
            if (std::find(PainiciJucator.begin(), PainiciJucator.end(), NumarulJucatorului) == PainiciJucator.end())
            {
                NrPainiciJucator++;
                PainiciJucator[pozjuc] = NumarulJucatorului; pozjuc++;
                VerificareCastig(NrPainiciJucator, NrPainiciCalculator);
                system("CLS"); Afisare(Jucator, Calculator);
                std::cout << "Acest numar are deja o painica. Alegeti alt numar.";
                JucareJucator(Jucator, Calculator, NumarulJucatorului, NumarulCalculatorului, NrPainiciJucator, NrPainiciCalculator, pozjuc, pozcalc, PainiciJucator, PainiciCalculator, Numere);
            }
            else
            {
                VerificareCastig(NrPainiciJucator, NrPainiciCalculator);
                system("CLS"); Afisare(Jucator, Calculator);
                std::cout << "Acest numar are deja o painica. Alegeti alt numar.";
                JucareJucator(Jucator, Calculator, NumarulJucatorului, NumarulCalculatorului, NrPainiciJucator, NrPainiciCalculator, pozjuc, pozcalc, PainiciJucator, PainiciCalculator, Numere);
            }
            VerificareCastig(NrPainiciJucator, NrPainiciCalculator);
        }
        else
            if (Jucator[NumarulJucatorului - 1] < 3 && NumarulJucatorului >= 1 && NumarulJucatorului <= 10)
            {
                AlegereRandomCalculator(NumarulCalculatorului, Calculator, Numere);
                if (NumarulJucatorului != NumarulCalculatorului)
                {
                    Jucator[NumarulJucatorului - 1] = Jucator[NumarulJucatorului - 1] + 1;
                    if (Jucator[NumarulJucatorului - 1] == 3)
                    {
                        if (std::find(PainiciJucator.begin(), PainiciJucator.end(), NumarulJucatorului) == PainiciJucator.end())
                        {
                            NrPainiciJucator++;
                            PainiciJucator[pozjuc] = NumarulJucatorului; pozjuc++;
                            VerificareCastig(NrPainiciJucator, NrPainiciCalculator);
                        }
                    }
                    VerificareCastig(NrPainiciJucator, NrPainiciCalculator);
                    system("CLS"); Afisare(Jucator, Calculator);
                    JucareJucator(Jucator, Calculator, NumarulJucatorului, NumarulCalculatorului, NrPainiciJucator, NrPainiciCalculator, pozjuc, pozcalc, PainiciJucator, PainiciCalculator, Numere);
                }
                else
                {
                    std::cout << "Calculatorul a ghicit numarul tau." << std::endl;
                    if (std::find(PainiciCalculator.begin(), PainiciCalculator.end(), NumarulCalculatorului) == PainiciCalculator.end())
                    {
                        Calculator[NumarulJucatorului - 1] = Calculator[NumarulJucatorului - 1] + 1;
                        system("CLS"); Afisare(Jucator, Calculator);
                        JucareCalculator(Jucator, Calculator, NumarulJucatorului, NumarulCalculatorului, NrPainiciJucator, NrPainiciCalculator, pozjuc, pozcalc, PainiciJucator, PainiciCalculator, Numere);
                    }
                    VerificareCastig(NrPainiciJucator, NrPainiciCalculator);
                    JucareCalculator(Jucator, Calculator, NumarulJucatorului, NumarulCalculatorului, NrPainiciJucator, NrPainiciCalculator, pozjuc, pozcalc, PainiciJucator, PainiciCalculator, Numere);
                }
            }
    }
    else
    {
        VerificareCastig(NrPainiciJucator, NrPainiciCalculator);
    }
    
}
void AlegereCineIncepe(int alegere, std::array<int, 10>& Jucator, std::array<int, 10>& Calculator, int &NumarulJucatorului, int &NumarulCalculatorului, int& NrPainiciJucator, int& NrPainiciCalculator,
    int& pozjuc, int& pozcalc, std::array<int, 9>& PainiciJucator, std::array<int, 9>& PainiciCalculator, std::vector<int> &Numere)
{
    switch (alegere)
    {
    case 0:
        std::cout << "Primul care incepe este Jucatorul.";
        JucareJucator(Jucator, Calculator, NumarulJucatorului, NumarulCalculatorului, NrPainiciJucator, NrPainiciCalculator, pozjuc, pozcalc, PainiciJucator, PainiciCalculator, Numere);
        break;
    case 1:
        std::cout << "Primul care incepe este Calculatorul.";
        JucareCalculator(Jucator, Calculator, NumarulJucatorului, NumarulCalculatorului, NrPainiciJucator, NrPainiciCalculator, pozjuc, pozcalc, PainiciJucator, PainiciCalculator, Numere);
        break;
    default:
        std::cout << " Numarul nu corespunde nici unui caz. Alegeti alt numar.";
        std::cin >> alegere;
        AlegereCineIncepe(alegere, Jucator, Calculator, NumarulJucatorului, NumarulCalculatorului, NrPainiciJucator, NrPainiciCalculator, pozjuc, pozcalc, PainiciJucator, PainiciCalculator, Numere);
        break;
    }

}
int main()
{
    std::array<int, 10> Jucator = { 0 }; // Cu functia fill Jucator.fill(0);
    std::array<int, 10> Calculator = { 0 }; // Cu functia fill calculator.fill(0); 
    int NumarulJucatorului = 0, NumarulCalculatorului = 0;
    int NrPainiciJucator = 0, NrPainiciCalculator = 0;
    int pozjuc = 0, pozcalc = 0;
    std::array<int, 9> PainiciJucator; std::array<int, 9> PainiciCalculator;

    std::vector<int> Numere = { 1,2,3,4,5,6,7,8,9,10 };
    Reguli();
    int alegere;
    std::cout << "Alegeti o valoare dintre 0-Jucator sau 1-Calculator pentru a alege cine incepe" << std::endl;
    std::cin >> alegere;
    AlegereCineIncepe(alegere, Jucator, Calculator, NumarulJucatorului, NumarulCalculatorului, NrPainiciJucator, NrPainiciCalculator, pozjuc, pozcalc, PainiciJucator, PainiciCalculator, Numere);

    return 0;
}
