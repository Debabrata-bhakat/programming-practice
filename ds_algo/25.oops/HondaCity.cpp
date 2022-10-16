class HondaCity : public Car{
public:
	HondaCity(int x, int y):Car(x,y){
		cout << "HondaCity constructor\n";
	}
	~HondaCity(){
		cout << "HondaCity destructor\n";
	}
};