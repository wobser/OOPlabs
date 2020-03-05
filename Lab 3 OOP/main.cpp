#include <cstdlib>
#include <iostream>

using namespace std;

enum Color { red, green, blue, black, purple };

class Wheel{
    friend class Pump;
private:
    double radius;
    double rpm;
    double angle;
    double pressure;
    const double pi = 3.1415926;
public:
    Wheel();// The default constructor, maorolfimasu
    
    virtual ~Wheel(){
        
    }
    
    Wheel(double rad); // The actual non-default constructor roflmao

    // Set and get stuff for Wheel
    
    double getRpm(){
        return rpm;
    }
    bool setRpm(double rpm){
        this -> rpm = rpm;
    }
    double getAngle(){
        return angle;
    }
    bool setAngle(double angle){
        if (angle > 35 || angle < 165) {
            this->angle = angle;
        }
        else
            return false;
        
    }
    bool setRadius (double radius){
        this -> radius = radius;
    }
    bool getRadius (){
        return radius;
    }
    bool operator == (const Wheel& wheel){
        double s1 = 2*pi*getRadius()*getRpm();
        double s2 = 2*pi*wheel.radius*wheel.rpm;
        return s1 == s2;
    }
    bool operator != (const Wheel& wheel){
        double s1 = 2*pi*getRadius()*getRpm();
        double s2 = 2*pi*wheel.radius*wheel.rpm;
        return s1 != s2;
    }
    bool operator < (const Wheel& wheel){
        double s1 = 2*pi*getRadius()*getRpm();
        double s2 = 2*pi*wheel.radius*wheel.rpm;
        return s1 < s2;
    }
    bool operator > (const Wheel& wheel){
        double s1 = 2*pi*getRadius()*getRpm();
        double s2 = 2*pi*wheel.radius*wheel.rpm;
        return s1 > s2;
    }
    bool operator <= (const Wheel& wheel){
        double s1 = 2*pi*getRadius()*getRpm();
        double s2 = 2*pi*wheel.radius*wheel.rpm;       
        return s1 <= s2;
    }
    bool operator >= (const Wheel& wheel){
        double s1 = 2*pi*getRadius()*getRpm();
        double s2 = 2*pi*wheel.radius*wheel.rpm;       
        return s1 >= s2;
    }
};

class Pump{
public:
    bool setPressure(Wheel& w1, double pressure){
        if (pressure <= 0) {
            return false;
        }
        w1.pressure = pressure;
    }
};

class car{
private:
    Color color;
    int weight;
    string model;
    double linearVelocity;
    double angularVelocity;
    Wheel * flWheel;
    Wheel * frWheel;
    Wheel * rlWheel;
    Wheel * rrWheel;
public:
    car(){
        flWheel = new Wheel(1.0);
        frWheel = new Wheel(1.0);
        rlWheel = new Wheel(1.0);
        rrWheel = new Wheel(1.0);
        cout << "default c-tor" << endl;
    };
    
    virtual ~car(){
        
    }

    car(double radius, Color color, string model){
        flWheel = new Wheel(radius);
        frWheel = new Wheel(radius);
        rlWheel = new Wheel(radius);
        rrWheel = new Wheel(radius);
        
        this->color = color;
        this->model = model;
        this->weight = 1200;
        this->angularVelocity = 0;
        this->linearVelocity = 0;
        
    };
    bool setSpeed(double speed){
        this->flWheel->setRpm(speed);
        this->frWheel->setRpm(speed);
        this->rlWheel->setRpm(speed);
        this->rrWheel->setRpm(speed);
        return true;
    }
    bool setTurningAngle(double angle){
        if(angle > 35 || angle < 165){
            this->flWheel->setAngle(angle);
            this->frWheel->setAngle(angle);
            this->angularVelocity = this->linearVelocity / angle;
        }
        
    }
    
    void printWheel(){
        cout << "Front left wheel Angle: " << this->flWheel->getAngle() << " RPM: " << this->flWheel->getRpm() << endl;
        cout << "Front right wheel Angle: " << this->frWheel->getAngle() << " RPM: " << this->frWheel->getRpm() << endl;
        cout << "Rear left wheel Angle: " << this->rlWheel->getAngle() << " RPM: " << this->rlWheel->getRpm() << endl;
        cout << "Rear right wheel Angle: " << this->rrWheel->getAngle() << " RPM: " << this->rrWheel->getRpm() << endl;
    }
    
    string getModel(){
        return this->model;
    }
    
    bool setModel(string vehicleModel){
        this -> model = vehicleModel;
        return true;
    }
    
    //A copy assignment operator, that should work...
    car & operator = (const car& vehicle){
        this -> color = vehicle.color;
        this -> model = vehicle.model;
        this -> weight = vehicle.weight;
        this -> angularVelocity = vehicle.angularVelocity;
        this -> linearVelocity = vehicle.linearVelocity;
        this -> flWheel = new Wheel(vehicle.flWheel->getRadius());
        this -> frWheel = new Wheel(vehicle.frWheel->getRadius());
        this -> rlWheel = new Wheel(vehicle.rlWheel->getRadius());
        this -> rrWheel = new Wheel(vehicle.rrWheel->getRadius());
        cout << "copy assignment operator has been called" << endl;
        return *this;
    }
    
    //COPY CONSTRUCTOR 
    car(car& vehicle){
        this -> flWheel = new Wheel(vehicle.flWheel->getRadius());
        this -> frWheel = new Wheel(vehicle.frWheel->getRadius());
        this -> rlWheel = new Wheel(vehicle.rlWheel->getRadius());
        this -> rrWheel = new Wheel(vehicle.rrWheel->getRadius());
        cout << "copy constructor has been called" << endl;
    }
    
    car (car&& vehicle){
        this -> color = vehicle.color;
        this -> model = vehicle.model;
        this -> weight = vehicle.weight;
        this -> angularVelocity = vehicle.angularVelocity;
        this -> linearVelocity = vehicle.linearVelocity;
        this -> flWheel = vehicle.flWheel;
        vehicle.flWheel = nullptr;
        this -> frWheel = vehicle.frWheel;
        vehicle.frWheel = nullptr;
        this -> rlWheel = vehicle.rlWheel;
        vehicle.rlWheel = nullptr;
        this -> rrWheel = vehicle.rrWheel;
        vehicle.rrWheel = nullptr;
        cout << "Move constructor has been called" << endl;
        cout << this->model << endl;
    }
    
    car & operator= (car&& vehicle){
        this ->color = vehicle.color;
        this ->model = vehicle.model;
        this ->weight = vehicle.weight;
        this ->angularVelocity = vehicle.angularVelocity;
        this ->linearVelocity = vehicle.linearVelocity;
        this ->flWheel = vehicle.flWheel;
        vehicle.flWheel = nullptr;
        this ->frWheel = vehicle.frWheel;
        vehicle.frWheel = nullptr;
        this ->rlWheel = vehicle.rlWheel;
        vehicle.rlWheel = nullptr;
        this ->rrWheel = vehicle.rrWheel;
        vehicle.rrWheel = nullptr;
        cout << "Move assignment operator has been called" << endl;
        cout << this->model << endl;
        return *this;
    }
};

 Wheel::Wheel(double rad){
        radius = rad;
        cout << "Object is being created, Wheel radius = " << radius << endl;
    }
 Wheel::Wheel(){
     cout << "Default constructor thingimajing" << endl;
 }


int main(int argc, char** argv) {
   /*
    //Part 4.1
    Wheel* w1 = new Wheel(1.0);
    w1 -> setRpm(20.0);
    Wheel* w2 = new Wheel(1.0);
    w2 -> setRpm(20.0 );
    Wheel* w3 = new Wheel(1.0);
    w3 -> setRpm(30.0 );
    Wheel* w4 = new Wheel(1.0);
    w4 -> setRpm(35.0 );
    
    if(*w1 == *w2)
        cout << "w1 equals w2" << endl;
    if(*w1 != *w3)
        cout << "w1 does not equal w3" << endl;
    if(*w2 < *w4)
        cout << "w2 is less than w4" << endl;
    if(*w3 > *w1)
        cout << "w3 is greater than w1" << endl;
    if(*w2 <= *w3)
        cout << "w2 is less or equal to w3" << endl;
    if(*w4 >= *w3)
        cout << "w4 is greater or equal to w3" << endl;
    */
   
    /*
    // Part 4.2
    car *c1 = new car;
    car *c2 = new car;
    *c2  = *c1; // copy assignment operator
    car *c3 = new car(*c2);//copy constructor
    // Both angular and linear are 0? When a car i created it stands still... right?
    */
    
    
    
    /* Part 3
    Pump p1;
    p1.setPressure(*w1,21.00);
    */
    
    /* Part 5 
    car *vehicle1 = new car(1.0,Color::black,"V60");
    car *vehicle3 = new car(1.0,Color::red,"A6");
    car *vehicle2 = new car();
    *vehicle2 = std::move(*vehicle1);
    car vehicle4 = std::move(*vehicle3);
    */
    
    /* Part 6 */
    car *c1 = new car(1.0,Color::black,"V60");
    car *c2 = new car(*c1); // copy constructor
    c1->setTurningAngle(90.0);
    c1->setSpeed(10.0);
    c2->setTurningAngle(100.0);
    c2->setSpeed(15.0);
    
    c1->printWheel();
    c2->printWheel();
    
    car *c3 = new car(1.0,Color::purple,"M5");
    car *c4 = new car(*c3);
    delete c3;
    c4->setTurningAngle(90.0);
    c4->setSpeed(10.0);
    c4->printWheel();
    /*Since i hade already done a deep copy before checking the
     wheel thing you asked for everything went fine, no problem #thumbsup*/
    
    delete c1, c2, c4;
    
    return 0;
}
