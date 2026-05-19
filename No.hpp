#ifndef NO_HPP // Include guard to prevent multiple inclusions
#define NO_HPP

template <typename T>
struct No{
    T info;
    No <T> *eloA, *eloP;
};

#endif // NO_HPP