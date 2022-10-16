class Vehicle{
private:
	int maxSpeed;
protected:
	int numTyres;
public:
	string color;
	// Vehicle(){
	// 	cout << "vehicle's default constructor" << endl;
	// }
	void print(){
		cout << "Vehicle" << endl;
	}
	Vehicle(int z){
		cout << "vehicle's parameterised constructor: " << z << endl;
		maxSpeed=z;
	}
	~Vehicle(){
		cout << "vehicle's default destructor" << endl;
	}
};
