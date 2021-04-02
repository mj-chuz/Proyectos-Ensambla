#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <map>
#include <stdexcept>
#include <string>
#include <vector>


template <typename IdType, typename SymbolType>
//template <typename SymbolType>
class Cards
{
  private: 
    IdType id;
    SymbolType symbol;
    
   // bool foundPair;
public:
  Cards()
  {}

  IdType getId()
  {
      return id;
  }

  void setId(IdType newId)
  {
      id=newId;
  }

  SymbolType getSymbol()
  {
      return  symbol;
  }

  void setSymbol(SymbolType newSymbol)
  {
      symbol=newSymbol;
  }

};

template <typename IdType, typename SymbolType>
class MemoryBoard
{

  private:
    int rows;
    int cols;
    std::vector<std::vector<Cards<IdType, SymbolType>>> card;
   
  public:
    MemoryBoard()
    {}
    MemoryBoard(int limitRow, int limitCol)
    : rows(limitRow)
    , cols(limitCol)
    {
        Cards<IdType, SymbolType> aux;
        for(int i=0; i<rows; i++)
        {
            std::vector<Cards<IdType, SymbolType>> v1;
            for (int j=0; j<cols; j++ )
            {
                v1.push_back(aux);
            }
            card.push_back(v1);
        }
    }
    
    
    void setCard(int row, int col, IdType id, SymbolType symbol)
    {
        card[row][col].setId(id);
        card[row][col].setSymbol(symbol);
    }

    void print() 
    {
        for(int i=0; i<rows; i++)
        {
            for (int j=0; j<cols; j++)
            {
                std::cout<< "[" << card[i][j].getSymbol() << "]"; 
            }
            std::cout<< std::endl;
        }
        std::cout<< std::endl;
    }
    
};


class MathExpression
{
    protected:
    int value1;
    int value2;

    public:
    MathExpression()
    {}
    ~MathExpression()
    {}
    virtual std::istream& load(std::istream& input)
    {
        input>>value1;
        input>>value2;
        return input;
    }

    virtual std::ostream& print(std::ostream& output)
    {
        output<<value1<< " " << value2;
        return output;
    }

    virtual int getId()
    {
       int result=0;
       result=value1+value2;
        return result;
    }

    friend inline std::istream& operator>>(std::istream& input, MathExpression& expresion)
    {
        return expresion.load(input);
    }

    friend inline std::ostream& operator<<(std::ostream& output, MathExpression& expression)//ESTO TIENE QUE SER UN PUNTERO NO REFERENCIA, con puntero no compila
    {
        return expression.print(output);
    }


};

class PowerExpression: public MathExpression
{
    public:

    PowerExpression()
    {
    }
    virtual ~PowerExpression()
    {}

    virtual std::ostream& print(std::ostream& output) override
    {
        output<<this->value1;
        if (this->value2!=1)
        {
            output<<"^"<< this->value2;
        }
        return output;
    }


    virtual int getId() override
    {
        int result;
        result=std::pow(this->value1, this->value2);
        return result;
    }

};



class RootExpression: public MathExpression
{
    public:
    RootExpression()
    {}
    virtual ~RootExpression()
    {}

    virtual std::ostream& print(std::ostream& output) override
    {
      
        if (this->value1!=2){
            output<<this->value1;
        }
        output<<"v"<<this->value2;
        return output;

    }

    virtual int getId() override
    {
        int result;
        result = std::pow(this->value1, 1.0/this->value2);
        return result;
    }

};


class LogExpression: public MathExpression
{
    public:
    LogExpression()
    {}
    virtual ~LogExpression()
    {}

    virtual std::ostream& print(std::ostream& output) override
    {
        output<<"log";

        if(this->value1!=10)
        {
            output<<this->value1;
        }
        output<<" "<<this->value2;
        return output;
    }

    virtual int getId() override
    {
        int result;
        result = std::log10(this->value2) / std::log10(this->value1);
        return result;
    }
};



template <typename IdType, typename SymbolType>
class MemoryGenerator
{
  private:
    std::multimap<IdType, SymbolType> cards;
    std::vector<IdType> identifiers;

  public:
    MemoryGenerator()
    {}
    void insert(IdType id, SymbolType symbol)
    {
        cards.insert({id, symbol});
        identifiers.push_back(id);
    }

    //error en el aleatorio
    void generate(int rows, int cols)
    {
        MemoryBoard<IdType, SymbolType> board(rows,cols);
        //board.add();
        std::vector<IdType> newIdentifiers;
        IdType randomIdentifier;

      for(size_t i=0; i<identifiers.size(); i++)
        {
            randomIdentifier= identifiers[std::rand() % identifiers.size()];
            newIdentifiers.push_back(randomIdentifier);
            newIdentifiers.push_back(randomIdentifier);
        }

        size_t ident=0;
        std::random_shuffle(newIdentifiers.begin(), newIdentifiers.end());
        


        for (int row=0; row<rows; row++)
        {
            for (int col=0; col<cols; col++)

            {
                IdType actualIdentifier=newIdentifiers[ident];

                std::vector<SymbolType> symbols;
               
               auto it = cards.equal_range(actualIdentifier);
               
               for(auto itr = it.first; itr != it.second; itr++){
                 

                   symbols.push_back(itr->second);
                    
                }
                
                SymbolType symbol= symbols[std::rand() % symbols.size()-1];
                board.setCard(row, col, actualIdentifier, symbol);
                
                //ident++;
            }
            ident++;
        }
        board.print();

    }
};

template <typename IdType, typename SymbolType>
class Test
{
  private: 

    MemoryGenerator<IdType, SymbolType> generator;
    IdType id;
    SymbolType symbol;
  public:
    Test()
    {}


    int createGenerator ()
    {
        std::string action;
        int row=0;
        int col=0;
        while(std::cin>>action)
        {
            if (action=="insert")
            {
                std::cin>>id;
                std::cin>>symbol;
                generator.insert(id, symbol);
           
            }else{
                    std::cin>>row;
                    std::cin>>col;
                    generator.generate(row, col);
            }
        }
        
        return 0;
    }


    MathExpression* createExpression(std::string operand)
    {
        if (operand=="power")
        {
            return new PowerExpression;
        }
        if (operand=="root")
        {
            return new RootExpression;
        }
        if (operand=="log")
        {
            return new LogExpression;
        }
        return nullptr;
    }

    int createMathGenerator()
    {
        std::string action;
        int row=0;
        int col=0;
        while(std::cin>>action)
        {
            if( action=="mathInsert")
                {
                    std::string operation;
                    std::cin>>operation;
                    MathExpression* expression=createExpression(operation);
                    std::cin>>*expression;
                    generator.insert(expression->getId(), expression);
                }else{
                    std::cin>>row;
                    std::cin>>col;
                    generator.generate(row, col);
                }


        }
        return 0;
    }

};


int main()
{
    int seed;
    std::cin>>seed;
    std::srand(seed);
    std::string idType;
    std::cin>>idType;
    std::string symbolType;
    std::cin>>symbolType;
    if (idType=="int"){

        if(symbolType=="int"){
            Test<int, int> test;
            return test.createGenerator();
        }
        if(symbolType=="char"){
            Test<int, char> test;
            return test.createGenerator();
        }
        if(symbolType=="double"){
            Test<int, double> test;
            return test.createGenerator();
        }
        if(symbolType=="std::string"){
            Test<int, std::string> test;
            return test.createGenerator();
        }
       if (symbolType=="Expression"){
            Test<int, MathExpression*> test;
            return test.createMathGenerator();
        }

    }
    if (idType=="char"){

        if(symbolType=="int"){
            Test<char, int> test;
            return test.createGenerator();
        }
        if(symbolType=="char"){
            Test<char, char> test;
            return test.createGenerator();
        }
        if(symbolType=="double"){
            Test<char, double> test;
            return test.createGenerator();
        }
        if(symbolType=="std::string"){
            Test<char, std::string> test;
            return test.createGenerator();
        }

    }
    if (idType=="double"){

        if(symbolType=="int"){
            Test<double, int> test;
            return test.createGenerator();
        }
        if(symbolType=="char"){
            Test<double, char> test;
            return test.createGenerator();
        }
        if(symbolType=="double"){
            Test<double, double> test;
            return test.createGenerator();
        }
        if(symbolType=="std::string"){
            Test<double, std::string> test;
            return test.createGenerator();
        }

    }
   if (idType=="std::string"){

        if(symbolType=="int"){
            Test<std::string, int> test;
            return test.createGenerator();
        }
        if(symbolType=="char"){
            Test<std::string, char> test;
            return test.createGenerator();
        }
        if(symbolType=="double"){
            Test<std::string, double> test;
            return test.createGenerator();
        }
        if(symbolType=="std::string"){
            Test<std::string, std::string> test;
            return test.createGenerator();
        }

    }
    return 0;
}