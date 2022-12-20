#include "utility.h"
#include "SeqList.h"
#include "Search.h"

void instructor(int &n, int &m, bool &manual) {
	cout << "欢迎来到查找实验程序\n"
		<< "在这里你可以比较顺序查找和二分查找的性能" << endl;
	cout << "是否手动输入线性表？[Y/N]";
	char mop;
	cin >> mop;
	if (mop == 'Y' || mop - 32 == 'Y') manual = true;
	else manual = false;

	cout << "请输入线性表中整数的个数：";
	cin >> n;
	while (n < 0) {
		cout << "输入有误，请重新输入：";
		cin >> n;
	}
	cout << "请输入查找的次数" << endl;
	cin >> m;
	while (m < 0) {
		cout << "输入有误，请重新输入：";
		cin >> m;
	}

	//cout << "是否需要有序？[Y/N]";
	//char op;
	//cin >> op;
	//if (op == 'Y' || op - 32 == 'Y') flag = true;
	//else flag = false;
}

int getRand(int n) {
	// 获取10n以内的随机数
	return rand() % (n * 10);
}

void create(int n, vector<int> &v, bool manual) {
	for (int i = 0; i < n; i ++) {
		int rnd;
		if (manual) cin >> rnd;
		else rnd = getRand(n);
		v.push_back(rnd);
	}
}

void getTime(timeb &t) {
	ftime(&t); 
}

void print(const vector<int> &v) {
	for (int i = 0; i < v.size(); i ++) {
		cout << v[i] << " ";
	}
	cout << endl;
}

void search(int n, int m, SeqList &l, int type) {
	timeb t1, t2;
	int success = 0, fail = 0;
	int successCnt = 0, failCnt = 0;
	getTime(t1);
	for (int i = 0; i < m; i ++) {
		//cout << "######################" << endl;
		Search::init();
		int rnd = getRand(n);
		if (rnd % 10 < 2) rnd *= -1;
		int res;

		if (type == 1) res = Search::seqSearch(l, l.begin(), l.end(), rnd);
		else if (type == 2) res = Search::binSearch(l, l.begin(), l.end(), rnd);
		else res = Search::recursiveBinSearch(l, l.begin(), l.end(), rnd);

		if (res == -1) fail++, failCnt += Search::getcnt();
		else success++, successCnt += Search::getcnt();
	}
	getTime(t2);
	cout << ">耗时" << (t2.time - t1.time) * 1000 + t2.millitm - t1.millitm << "ms" << endl;
	cout << "成功次数：" << success << ", 成功平均比较次数：" << (success == 0 ? 0 : successCnt / success) << endl;
	cout << "失败次数：" << fail << ", 失败平均比较次数：" << (fail == 0 ? 0 : failCnt / fail) << endl;
}

int main() {

	srand((unsigned)time(NULL));

	int n, m;
	//int type;
	//bool flag;
	bool manual;
	instructor(n, m, manual);

	vector<int> nums;
	create(n, nums, manual);
	SeqList l(nums);

	cout << "生成的线性表为：" << endl;
	if (l.size() <= 100) {
		l.print();
	}
	else {
		for (int i = 0; i < 100; i++) {
			cout << l[i] << " ";
		}
		cout << "...（省略" << l.size() - 100 << "个数字）" << endl;
	}

	cout << endl;

	int success = 0, fail = 0;
	int successCnt = 0, failCnt = 0;

	cout << "*****************************************" << endl;
	cout << "顺序查找（无序）：" << endl;
	search(n, m, l, 1);

	l.sort(l.begin(), l.end());
	cout << "*****************************************" << endl;
	cout << "顺序查找（有序）：" << endl;
	search(n, m, l, 1);

	cout << "*****************************************" << endl;
	cout << "二分查找（递归）：" << endl;
	search(n, m, l, 2);


	cout << "*****************************************" << endl;
	cout << "二分查找（非递归）：" << endl;
	search(n, m, l, 3);

	system("pause");

	return 0;
}