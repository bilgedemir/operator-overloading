#include<iostream>
using namespace std;

class fraction {
private:
	int num, denom;
  // "*" operator overloading, friend ile belirttiğimiz için class dışında private üyeleri de alabiliyoruz.
	friend fraction operator*(fraction& obj1, fraction& obj2); //function declaration 
public:
	fraction() {

	}

	fraction(int n, int d) { //parametreli class constructor
		num = n;
		denom = d;
	}


	int getnum() {
		return num;
	}

	int getdenom() {
		return denom;
	}

	void setnum(int n) {
		num = n;
	}

	void setdenom(int d) {
		denom = d;
	}
     // + için operator overloading definition 
    fraction operator + (fraction& obj) {  
		fraction res;
		res.num = num * obj.denom + obj.num * denom;
		res.denom = denom * obj.denom;
		return res;
	}
		 // - için operator overloading definition 
    friend fraction operator -(fraction& obj1, fraction &obj2) {
		fraction res;
		res.num = obj1.num * obj2.denom - obj1.denom * obj2.num;
		res.denom = obj1.denom*obj2.denom;

		return res;
	}
     // toplama işleminin ve çıkarma işleminin sonucunun karşılaştırmasını == operator overloading ile yapıyoruz
	 bool operator ==(fraction& obj) {
		 if (num == obj.num && denom == obj.denom) {
			 return true;
		 }
		 else
			 return false;

	}

   //  "/" operator overloading 
	 fraction operator /(fraction& obj); //function declaration 

	
};

// "/" operator overloading definition
fraction fraction ::operator/(fraction& obj) {
	fraction res;
	res.num = num * obj.denom;
	res.denom = denom * obj.num;
	return res;
}


// "*" operator overloading definition 
fraction operator*(fraction& obj1, fraction& obj2) {
	fraction res;
	res.num = obj1.num * obj2.num;
	res.denom = obj1.denom * obj2.denom;
	return res;
}



int main() {

	fraction f1(2, 3); //parametreli constructor çağırma
	fraction f2(3, 5); //parametreli constructor çağırma
	fraction f3 = f1 + f2;
	fraction f4 = f1 - f2;
	fraction f5 = f3 / f4;

	fraction f6 = operator*(f3,f4); // çarma işemini  yapacak operator overloading çağırma
	
	/*fraction f7 = f3 * f4; --> //f6 ile aynı anlama geliyor*/

	cout << "addition = " << f3.getnum() << "/" << f3.getdenom() << endl; 
	cout << "subtraction = " << f4.getnum() << "/" << f4.getdenom() << endl;

	if (f3.operator==(f4)) //eşit olup olmadığını kontrol etme
		cout << "they are EQUAL\n";
	cout << "they are NOT EQUAL\n";


	cout << "division = " << f5.getnum() << "/" << f5.getdenom() << endl;

	cout << "multi resutl = " << f6.getnum() << "/" << f6.getdenom() << endl;

	cout << "**************************\n";

	

	return 0;
}



/* output:
  
addition = 19/15
subtraction = 1/15
they are NOT EQUAL
division = 285/15
multi resutl = 19/225
**************************
*/
