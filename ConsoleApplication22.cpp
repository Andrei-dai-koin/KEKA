#include <iostream>
#include <string>
using namespace std;
class Book {
private:
    string title;
    string author;
    int pages;
    double price;

public:
    Book()
    {
        string title = "NONE";
        string author = "NONE";
        int pages = 0;
        double price = 0.0;
        
    }
    Book(string title,string author, int pages, double price)
    {
        this->title = title;
        this->author = author;
        this->pages = pages;
        this->price = price;

    }


    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    int getPages() const { return pages; }
    double getPrice() const { return price; }

    void setTitle(string newTitle) { title = newTitle; }
    void setAuthor(string newAuthor) { author = newAuthor; }
    void setPages(int newPages) { pages = newPages; }
    void setPrice(double newPrice) { price = newPrice; }

    
    string getInfo()  {
        return "Заголовок: " + title + ", Автор: " + author + ", Страницы: " + to_string(pages) + ", Цена: $" + to_string(price);
    }

    
    string getBookClass()  {
        if (pages < 100) {
            return "Короткая книга";
        }
        else if (pages <= 300) {
            return "Книга среднего размера";
        }
        else {
            return "Длинная книга";
        }
    }
};

int main() {
   setlocale(LC_ALL, "RU");
    const int MAX_BOOKS = 100; 
    Book books[MAX_BOOKS];      
    int bookCount = 0;        
    int choice = 0;

    while (choice != 6) {
        
        cout << "\nМеню:\n";
        cout << "1. Добавить пустую книгу\n";
        cout << "2. Добавить книгу с данными\n";
        cout << "3. Редактировать книгу\n";
        cout << "4. Показать все книги\n";
        cout << "5. Сортировать книги по названию\n";
        cout << "6. Выход\n"; 

        

        if (cin.fail())
        {
            cin.clear();

            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        
        cout << "Введите ваш выбор: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            if (bookCount < MAX_BOOKS) {
                books[bookCount++] = Book();  
                cout << "Добавлена ​​пустая книга.\n";
            }
            else {
                cout << "Массив книг заполнен.\n";
            }
            break;
        }
        case 2: {
            if (bookCount < MAX_BOOKS) {
                string title, author;
                int pages;
                double price;

                cout << "Введите название: ";
                getline(cin, title);
                cout << "Введите автора: ";
                getline(cin, author);
                cout << "Введите количество страниц: ";
                cin >> pages;
                cout << "Введите цену: ";
                cin >> price;

                books[bookCount++] = Book(title, author, pages, price);  
                cout << "Книга добавлена.\n";
            }
            else {
                cout << "Массив книг заполнен.\n";
            }
            break;
        }
        case 3: {
            int index;
            cout << "Введите индекс книги для редактирования (от 0 до " << bookCount - 1 << "): ";
            cin >> index;

            if (index >= 0 && index < bookCount) {
                cout << "Редактирование книги: " << books[index].getInfo() << "\n";
                int fieldChoice;
                cout << "Какое поле вы хотели бы отредактировать? (1 - название, 2 - автор, 3 - страницы, 4 - цена): ";
                cin >> fieldChoice;

                switch (fieldChoice) {
                case 1: {
                    string newTitle;
                    cout << "Введите новое название: ";
                     
                    getline(cin, newTitle);
                    books[index].setTitle(newTitle);
                    break;
                }
                case 2: {
                    string newAuthor;
                    cout << "Введите нового автора: ";
                      
                    getline(cin, newAuthor);
                    books[index].setAuthor(newAuthor);
                    break;
                }
                case 3: {
                    int newPages;
                    cout << "Введите новое количество страниц: ";
                    cin >> newPages;
                    books[index].setPages(newPages);
                    break;
                }
                case 4: {
                    double newPrice;
                    cout << "Введите новую цену: ";
                    cin >> newPrice;
                    books[index].setPrice(newPrice);
                    break;
                }
                default:
                    cout << "Неверное поле.\n";
                }
                cout << "Книга обновлена.\n";
            }
            else {
                cout << "Неверный индекс.\n";
            }
            break;
        }
        case 4: {
            for (int i = 0; i < bookCount; ++i) {
                cout << i << ": " << books[i].getInfo()
                    << " | Class: " << books[i].getBookClass() << "\n";
            }
            break;
        }
        case 5: {
            for (int i = 0; i < bookCount - 1; ++i) {
                for (int j = i + 1; j < bookCount; ++j) {
                    if (books[i].getTitle() > books[j].getTitle()) {
                       
                        Book temp = books[i];
                        books[i] = books[j];
                        books[j] = temp;
                    }
                }
            }
            cout << "Книги отсортированы по названию.\n";
            break;
        }
        case 6:
            cout << "Выход из программы.\n";
            
        default:
            cout << "Неверный выбор. Попробуйте еще раз.\n";
        }
    }
}