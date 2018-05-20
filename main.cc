#include <chrono>
#include <functional>
#include <iostream>
#include <random>

void doNothing()
{
    int j = 40;
    for (int i=0; i<100; ++i) {
        j += i;
        j -= i;
    }
    j -= 40;
    std::cout << j << std::endl;
}

auto setupExperiment()
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<int> distribution(1, 6);
    auto dice = std::bind(distribution, generator);
    return dice;
}

void runExperiment()
{
    auto dice = setupExperiment();
    int wisdom = dice()+dice()+dice();
    std::cout << wisdom << std::endl;

    doNothing();
}

int main()
{
    runExperiment();
    return EXIT_SUCCESS;
}