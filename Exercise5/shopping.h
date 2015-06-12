// shopping.h declares the Shopping class
#ifndef SHOPPING
#define SHOPPING
class Shopping
{
    protected:
        static Shopping *tail; // class attribute
        int QTY;
    
        int size;
    public:
        Shopping(int, char *); // constructor
        //Shopping();
        void addItem(Shopping *&);
        void show();
        void clean();
        void sortByItemName(Shopping* head);
    char item[21];
    Shopping *next;

}; // Shopping
#endif