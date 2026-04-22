#pragma once
#include <vector>
#include <random>
#include <algorithm>



class RData
{
private:
    static std::random_device random_data;   // Noise data

public:
    // Hard math method
    static std::mt19937& getRandNum()
    {
        unsigned int seed_data[8];
        for (unsigned int& val : seed_data) { val = random_data(); }
        static std::seed_seq seed(std::begin(seed_data), std::end(seed_data)); // Set seed

        static std::mt19937 gen(seed);  // Random numbers generation
        return gen;
    }

    // Simple math method
    static std::minstd_rand& getFastRandNum()
    {
        static std::minstd_rand fast_gen(random_data()); // Fast random numbers generation
        return fast_gen;
    }

    static std::random_device& getRData() { return random_data; }
};

std::random_device RData::random_data;



//--------------------
//----Random value----
//--------------------


namespace betrand
{
    //===================
    //=====INT TYPE======
    //===================
    
    // Hard math random
    template<typename T>
    T rand_I(const T MIN, const T MAX)
    {
        std::uniform_int_distribution<T> dist(MIN, MAX); // Set number range
        return dist(RData::getRandNum());
    }


    // Simple math random
    template<typename T>
    T rand_I_fast(const T MIN, const T MAX)
    {
        std::uniform_int_distribution<T> dist(MIN, MAX); // Set number range
        return dist(RData::getFastRandNum());
    }

    //===================
    //====FLOAT TYPE=====
    //===================

    // Hard math random
    template<typename T>
    T rand_F(const T MIN, const T MAX)
    {
        std::uniform_real_distribution<T> dist(MIN, MAX); // Set number range
        return dist(RData::getRandNum());
    }


    // Simple math random
    template<typename T>
    T rand_F_fast(const T MIN, const T MAX)
    {
        std::uniform_real_distribution<T> dist(MIN, MAX); // Set number range
        return dist(RData::getFastRandNum());
    }
}



//--------------------
//----Distribution----
//--------------------

namespace betrand
{
    bool chance(const double value)
    {
        std::bernoulli_distribution distribution(std::abs(value)); // Set chance
        return distribution(RData::getRandNum());
    }

    unsigned int chance_to_attempts(const double value)
    {
        std::geometric_distribution<unsigned int> gdistribution(value); // Set chance
        return gdistribution(RData::getRandNum());
    }

    template<size_t epsilon>
    double normal_distribution()
    {
        double normDist = std::generate_canonical<double, epsilon>(RData::getRData());
        return normDist;
    }
}



//--------------------
//-------Arrays-------
//--------------------

namespace betrand
{
    // Shuffle data
    template<typename T>
    void shuffle(std::vector<T> &arr)
    {
        std::shuffle(arr.begin(), arr.end(), RData::getRandNum());
    }

    // Select random data
    template<typename T>
    void rand_select(std::vector<T>& original, std::vector<T>& result, int num)
    {
        std::sample(original.begin(), original.end(),
                    std::back_inserter(result),
                    num, RData::getRandNum());
    }

    // Generate random data
    template<typename T>
    void generate_data(std::vector<T>& arr, size_t size, const T MIN, const T MAX)
    {
        arr.resize(size);

        if constexpr (std::is_integral_v<T>)
        {
            std::uniform_int_distribution<T> dist(MIN, MAX);
            auto& gen = RData::getRandNum();
            std::generate(arr.begin(), arr.end(), [&dist, &gen]() { return dist(gen); });
        }
        else if constexpr (std::is_floating_point_v<T>)
        {
            std::uniform_real_distribution<T> dist(MIN, MAX);
            auto& gen = RData::getRandNum();
            std::generate(arr.begin(), arr.end(), [&dist, &gen]() { return dist(gen); });
        }
    }
}