#ifndef NUMEROCOMPLEJO_H
#define NUMEROCOMPLEJO_H


class numeroComplejo
{
public:
    numeroComplejo();
    numeroComplejo(double real, double imaginario);

    numeroComplejo operator+(numeroComplejo otro);

    numeroComplejo operator-(numeroComplejo otro);
};

#endif // NUMEROCOMPLEJO_H
