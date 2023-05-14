class Vehicle{
        
    public:
        
        string brand; // Brand Name
        string model; // Model Name
        int weight; // Weight of Vehicle
        int fuelCapacity; // Fuel Tank Capacity
        float mileage; // Mileage
        string numPlate; // Number plate
        
        /* Functions */
};

class Car : public Vehicle{
    
    public:
     
        string engineName; // Engine 
        int bootSpace; // Capacity of boot
        string type; // SUV, MUV, etc..
        
        /* Functions */
    
};

class Truck :public Vehicle{
    
    public:
    
        int loadCapacity; // Load carrying capacity
        int numWheels; // Number of Wheels
        string chassisType; // Chassis Type
        
        * Functions */
}

