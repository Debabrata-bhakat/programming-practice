class Polynomial{
    private:
    int *degCoeff;
    int capacity;

    public:
    // Default constructor
    Polynomial(){
        degCoeff = new int[5];
        capacity = 5;
        for (int i = 0; i < 5; i++)
        {
            degCoeff[i] = 0;
        }
        
    }
    //Copy constructor
    Polynomial(Polynomial const &p){
        // this ->degCoeff = p.degCoeff; shallow copy
        //Deep copy
        int *newpoly = new int [p.capacity];
        for (int i = 0; i < p.capacity; i++)
        {
            newpoly[i] = p.degCoeff[i];
        }
        this ->degCoeff = newpoly;
        this ->capacity = p.capacity;
    }
    //Copy assignment operator
    void operator=(Polynomial const &p){
        // this ->degCoeff = p.degCoeff; shallow copy
        //Deep copy
        int *newpoly = new int [p.capacity];
        for (int i = 0; i < p.capacity; i++)
        {
            newpoly[i] = p.degCoeff[i];
        }
        this ->degCoeff = newpoly;
        this ->capacity = p.capacity;
    }
    void print()const{
        for (int i = 0; i < this->capacity; i++)
        {
            cout << this ->degCoeff[i] << "x" << i << " ";
        }        
    }
    void setCoefficient(int coeff, int index){
        while(index >= this ->capacity){
            int *newcoeff = new int[this ->capacity *2];
            for (int i = 0; i < this->capacity; i++)
            {
                newcoeff[i] = this ->degCoeff[i];
            }
            
            for (int i = this ->capacity; i < this->capacity*2; i++)
            {
                newcoeff[i] = 0;
            }            
            this ->capacity *=2;
            this ->degCoeff = newcoeff;
            delete [] newcoeff;
        }
        this ->degCoeff[index] = coeff;
    }
    Polynomial operator+(Polynomial const &p2){
        Polynomial p3;
        if(this ->capacity > p2.capacity){
            p3 = *this;
            for (int i = 0; i < p2.capacity; i++)
            {
                p3.degCoeff[i] = this ->degCoeff[i] + p2.degCoeff[i];
            }
            
        }
        else {
            p3 = p2;
            for (int i = 0; i < this ->capacity; i++)
            {
                p3.degCoeff[i] = this ->degCoeff[i] + p2.degCoeff[i];
            }
        }
        return p3;
    }
};