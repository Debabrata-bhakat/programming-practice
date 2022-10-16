// #include "Vehicle.cpp"
class Car:virtual public Vehicle{
public:
	Car():Vehicle(3){
		cout << "car's default constructor" << endl;
	}
	int numGears;
	// Car(int x, int y): Vehicle(x){
	// 	cout << "car's constructor\n";
	// 	numGears=y;
	// }
	~Car(){
		cout << "car's default destructor" << endl;
	}

	void print(){
		cout << "numTyres: " << numTyres << endl;
		cout << "color: " << color << endl;
		cout << "numGears: " << numGears << endl;
	}
};