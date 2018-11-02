#include <iostream>
#include "linked-list.h"

using namespace std;

int main()
{
    cout << "Linked List" << endl;
    List list;
    int opt, value, n;
    Node *aux;
    do{
        cout<<"1-insert"<<endl;
        cout<<"2-insert in the end"<<endl;
        cout<<"3-insert in the begining"<<endl;
        cout<<"4-remove"<<endl;
        cout<<"5-search"<<endl;
        cout<<"6-show"<<endl;
        cout<<"9-exit"<<endl;
        cout<<"select:";
        cin>>opt;
        switch(opt){
        case 1:
			if(!list.emptyList()){
            	cout<<"Type a value:";
            	cin>>value;
				do{
					cout<<"Type the element of the list:";
					cin>>n;
				}while(n>list.numberElements());
				list.setValueBetween(value, n);
			}
			else{
            	cout<<"Type a value:";
				cin>>value;
				list.setValueLast(value);
			}
			break;
        case 2:
            cout<<"Type a value:";
			cin>>value;
			list.setValueLast(value);
			break;
        case 3:
            cout<<"Type a value:";
			cin>>value;
			list.setValueBegin(value);
			break;
        case 4:
            if(list.emptyList()){
                cout<<"empty list...."<<endl;
            }
            else{
				do{
					cout<<"Type the element of the list to delete:";
					cin>>n;
				}while(n>list.numberElements());
                list.deleteElement(n);
			}
			break;
		case 5:
			if(!list.emptyList()){
				cout<<"Type the number you want to search:";
				cin>>value;
				if(list.searchValue(value))
					cout<<"This value is on the list."<<endl;
				else
					cout<<"This value is not on the list."<<endl;
			}
			else
                cout<<"empty list...."<<endl;	
			break;
		case 6:
			if(!list.emptyList()){
				aux = list.header;
				while(aux != NULL){
					cout<<aux->info<<" ";
					aux = aux->next;
				}
				cout<<endl;
			}
			else
                cout<<"empty list...."<<endl;
			break;
        case 9:
            cout<<"end..."<<endl;
            break;
        default:
            cout<<"invalid option"<<endl;
            break;
        }

    }while(opt != 9);

    return 0;
}
