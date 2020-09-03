#ifndef IEXCHANGE_H
#define IEXCHANGE_H

class IExchange
{
public:
   virtual double exchange(int const& arg) = 0;
   virtual ~IExchange () {};
};

#endif // IEXCHANGE_H
