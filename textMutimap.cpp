#include <iostream>
#include <string>
#include <vector>
#include <map>


using namespace std;
const int mconst=1;

//#ifdef 0
//
//class worker
//{
//public:
//	int id;
//	string name;
//	int wage;
//
//
//	worker();
//	~worker();
//
//private:
//
//};
//
//worker::worker()
//{
//}
//
//worker::~worker()
//{
//}
//
//void CreatWorker(vector<worker>& v){
//
//	string nameplus = "ABCDEFGHIJKML";
//	for (int i = 0; i < 5; i++)
//	{
//		worker p;
//		p.name = "student";
//		p.name += nameplus[i];
//		p.id = 1000 + i;
//		p.wage = rand() % 1000 + 3000;
//		v.push_back(p);
//	}
//}
//
//void DividToDepartment(vector<worker>&v, multimap<int, worker>& map){
//	for (vector<worker>::iterator ii = v.begin(); ii !=v.end(); ii++)
//	{
//		int deparment = rand() % 3 + 1;
//		//pair<int, worker> temp(deparment, *ii);//���ַ���ʹ�óɹ�������һ�֣�
//		//map.insert(temp);
//		map.insert(make_pair(deparment, *ii));	//ʹ�óɹ������ַ��������У�
//	}											//map�ĳ�ʼ������map.insert(pair<int,worker>(10,*ii));
//												//map.insert(map<int,worker>::value_type(10,*ii));
//												//map[10]=*ii;���ַ�������ļ�ֵ10����value��û��10�Ļ�����룻
//}
//
//void displayResult(multimap<int, worker>&map){
//	cout << "����1��" << endl;
//	multimap<int, worker>::iterator jj = map.find(1);
//	int count = map.count(1);
//	for (multimap<int, worker>::iterator ij = jj; count--;ij++)
//	{
//		cout << "name:" << ij->second.name << " id:" << ij->second.id << " wage:" << ij->second.wage << endl;
//	}
//	//�˴����Գɹ���equal_range�������ص�˳�����lower_bound���ݣ���upper_bound������������������vector��Ҳ�У�
//
//	//pair<multimap<int, worker>::iterator, multimap<int, worker>::iterator> temp1 = map.equal_range(1);
//	//cout << "lower range:" << temp1.first->second.name << "  upper range:" << temp1.second->second.name << endl;
//
//	//multimap<int, worker>::iterator temp2 = map.lower_bound(1);
//	//cout << "lower bound:" << temp2->second.name << endl;
//	//temp2 = map.upper_bound(1);
//	//cout << "upper_bound:" << temp2->second.name << endl;
//
//	// map�Զ�������map(MyKey,int ,MyCompare) mymap; bool MyCompare(MyKey k1,MyKey k2){return k1.id>k2.id;}
//
//	cout << "����2��" << endl;
//	multimap<int, worker>::iterator jj1 = map.find(2);
//	 count = map.count(2);
//	for (multimap<int, worker>::iterator ij = jj1; count--; ij++)
//	{
//		cout << "name:" << ij->second.name << " id:" << ij->second.id << " wage:" << ij->second.wage << endl;
//	}
//	cout << "����3��" << endl;
//	multimap<int, worker>::iterator jj2 = map.find(3);
//	 count = map.count(3);
//	for (multimap<int, worker>::iterator ij = jj2; count--; ij++)
//	{
//		cout << "name:" << ij->second.name << " id:" << ij->second.id << " wage:" << ij->second.wage << endl;
//	}
//}
//
//#endif

int main(){

//#ifdef 0
//	vector<worker> vec;
//	multimap<int, worker> mapresult;
//	CreatWorker(vec);
//	DividToDepartment(vec,mapresult);
//	displayResult(mapresult);
//
//	int abc;
//	cin >> abc;
//#endif

	int *mconstp = const_cast<int*>(&mconst);
//	*mconstp = 0;	//�˴����г������⣬��������������ĳ�����ֵ����ͬ���������ܻ���ֲ�ͬ�����
	cout << "const int=" << mconst << ";modify=" << *mconstp << endl;
	cout << "the adress:" << &mconst << "; pointer's address:" << mconstp << endl;
	system("pause");
	return 0;
}