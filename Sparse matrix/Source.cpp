#include "matrix.h"

matrix chooseFile();
int orders();
void doing_orders(matrix&);

int main()
{
    matrix m = chooseFile();
    doing_orders(m);
    return 0;
}

matrix chooseFile()
{
    cout << "=========== WELCOME ===========\n\n\n";
    
    cout << "1) M(10,5).csv\n";
    cout << "2) M(300,200).csv\n";
    cout << "3) M(7000,9000).csv\n\n";
    cout << "Choose a file: ";
    int f;
    cin >> f;
    if (f == 1) {
        matrix m(10, 5);
        return m;
    }
    if (f == 2) {
        matrix m(300, 200);
        return m;
    }
    if (f == 3){
        matrix m(7000, 9000);
    return m;
    }
    system("cls");
    matrix m(0, 0);
    return m;
}

int orders()
{
    system("cls");
    cout << "\n0) Insert\n1) Delete\n2) Search\n3) Update\n4) Print\n5) Save\n6) Exit\n\n";
    int o;
    cout << "Enter the order number: ";
    cin >> o;
    return o;
}

void doing_orders(matrix &m)
{
    int o = orders();
    while (o != 6) {
        system("cls");
        int row, col, value, a;
        char x;
        switch (o)
        {
        case 0:
            cout << "Insert a value into the matrix\n\n";
            cout << "Which row? ";
            cin >> row;
            cout << "Which col? ";
            cin >> col;
            cout << "Enter the value: ";
            cin >> value;
            m.insert(row, col, value);
            break;
        case 1:
            cout << "Change a node value to 0\n\n";
            cout << "Which row? ";
            cin >> row;
            cout << "Which col? ";
            cin >> col;
            a = m.Delete(row, col);
            cout << a << " deleted.\n";
            cout << "Enter a charactr for back.\n";
            cin >> x;
            break;
        case 2:
            cout << "Search a value\n\n";
            cout << "Enter the value: ";
            cin >> value;
            m.search(value);
            cout << "Enter a charactr for back.\n";
            cin >> x;
            break;
        case 3:
            cout << "Update a node\n\n";
            cout << "Which row? ";
            cin >> row;
            cout << "Which col? ";
            cin >> col;
            cout << "Enter the new value: ";
            cin >> value;
            m.update(row, col, value);
            break;
        case 4:
            cout << "Print the matrix\n\n";
            cout << "0) Print in matrix format\n";
            cout << "1) Print in Compressed format\n";
            int p_type;
            cout << "\nEnter the print format number: ";
            cin >> p_type;
            m.print(p_type);
            cout << "Enter a charactr for back.\n";
            cin >> x;
            break;
        case 5:
            cout << "Enter a charactr for save file: ";
            cin >> x;
            m.save();
            cout << "File saved. Enter a charactr for back.\n";
            cin >> x;
            break;
        default:
            break;
        }
        o = orders();
    }
}
