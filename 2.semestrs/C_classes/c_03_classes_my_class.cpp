class myClass
{
    private:
        int a;
        int b;

    
    public:

        myClass(); //constructor
        myClass(int x, int y); //constructor
        myClass(int x); //constructor
        ~myClass(); //destructor
        void set_a (int num);
        int get_a ();
        void set_b (int num);
        int get_b ();
    };