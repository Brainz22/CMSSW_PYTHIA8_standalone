#include "Pythia8/Pythia.h"
using namespace Pythia8;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: ./testCard testCard.dat" << std::endl;
        return 1;
    }
    Pythia pythia;
    pythia.readFile(argv[1]);
    pythia.init();

    // Run 10 events as a quick test
    for (int i = 0; i < 10; ++i) pythia.next();

    pythia.stat();
    return 0;
}
