#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

class Comp {
private:
  int akk = 0;
  std::unordered_map<int, int> ram; // hashmap weil schneller als array

  size_t cursor = 0;
  std::vector<std::pair<std::string, int>> program;

  void ldaa(int x); // lädt RAM-Adresse in akkumulator
  void ldaz(int x); // lädt die Zahl x in den akkumulator
  void load(); // lädt die Zahl aus er Speicherstelle, deren addresse im Akku
               // steht in den Akku
  void addz(int x); // addiert die Zahl x zum akkumulator
  void adda(int x); // addiert den wert der speicherstelle x zum akkumulator

  void mulz(int x); // multipliziert die Zahl x zum akkumulator
  void mula(int x); // multipliziert wert der speicherstelle x zum akkumulator

  void wra(int x); // schreibt zahl aus akkumulator in speicherstelle x
  void jmp(int x); // sprint zu programmzeile x und führt das programm ab da
                   // fort
  void jiz(int x); // springt zu programmzeile x wenn der akku den wert 0
                   // enthält
  void jnz(int x); // springe zu programmzeile x wenn der akku nicht den wert 0
                   // enthält

  void dispa(); // zeigt den wert des Akkus auf dem bildschirm an

  void stop(); // hält das programm an(ende des progamms)

  void matcher(std::string command, int x = 0);
  // dieser nimmt einen string wert und matcht diesen
  // zur passenden funktion

public:
  Comp();
  ~Comp();
  void writeRam(int mem, int val); // wrapper für key value creation
  int getRam(int mem);             // wraper für hashmap getter
  void loadProgram(const std::vector<std::pair<std::string, int>> &newProgram);
  void run();
};
