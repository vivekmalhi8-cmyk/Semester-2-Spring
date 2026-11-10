#ifndef PAKWHEELS_H
#define PAKWHEELS_H
#include <iostream>
using namespace std;

class Seller;
class Buyer;
class Listing;
class Message;
class FavoriteList;

class User {
private:
    int userID;
    string name,email,phone,password;
protected:
    string role;
public:
    User();
    User(int,string,string,string,string);
    User(const User&);
    string getName() const;
    string getEmail() const;
    string getPhone() const;
    int getUserID() const;
    string getRole() const;
    void setPhone(string);
    void setPassword(string);
    void Login(string,string);
    void Logout();
    void UpdateProfile(string,string);
    void DisplayProf() const;
};

class Vehicle {
private:
    string brand,model;
    int year;
    double price,mileage;
public:
    Vehicle();
    Vehicle(string,string,int,double,double);
    Vehicle(const Vehicle&);
    string getBrand() const;
    string getModel() const;
    int getYear() const;
    double getPrice() const;
    double getMileage() const;
    void setPrice(double);
    void Display() const;
    void UpdatePrice(double);
    double CalculateDepreciation();
    bool MatchFilter(string,double,double) const;
};

class Car:public Vehicle {
private:
    string fuelType,transmission,body_type;
    int engine_capacity;
    bool registered;
public:
    Car();
    Car(string,string,int,double,double,string,string,int,string,bool);
    Car(const Car&);
    string getFuelType() const;
    string getTransmission() const;
    int getEngineCapacity() const;
    string getBodyType() const;
    bool getRegistrationStatus() const;
    void Display() const;
    void updateRegis(bool);
    void CalculateTax();
    void showSpecs() const;
};

class Listing {
private:
    int listing_id;
    Car car_details;
    Seller* seller;
    bool Approve;
    string Description;
public:
    Listing();
    Listing(int,const Car&,Seller*,string);
    Listing(const Listing&);
    int getListingID() const;
    bool getApprovalStatus() const;
    string getDescription() const;
    Seller* getSeller() const;
    Car getCarDetails() const;
    void DisplayListing() const;
    void markApprove();
    void markUnApprove();
    void UpdateDescription(string);
};

class FavoriteList {
private:
    Listing* listings[50];
    int count;
    const int maxSize;
    int listId;
    string create_date;
public:
    FavoriteList();
    FavoriteList(int,string);
    FavoriteList(const FavoriteList&);
    int getCount() const;
    int getMaxSize() const;
    int getListID() const;
    string getCreatedDate() const;
    void AddToFav(Listing*);
    void RemoveFav(int);
    void DisplayFav() const;
    bool isFull() const;
};

class Message {
private:
    int msgId;
    string content;
    Buyer* Sender;
    Seller* Receiver;
    string time_stamp;
public:
    Message();
    Message(int,string,Buyer*,Seller*,string);
    Message(const Message&);
    int getMessageID() const;
    string getContent() const;
    string getTimestamp() const;
    Buyer* getSender() const;
    Seller* getReceiver() const;
    void SendMsg();
    void DisplayMsg() const;
    void deleteMsg();
    void MarkRead();
};

class Seller:public User {
private:
    Listing* listings[100];
    int listingCount;
    static int totalSellers;
    const int maxListings;
    double rating;
public:
    Seller();
    Seller(int,string,string,string,string,double);
    Seller(const Seller&);
    int getListingCount() const;
    double getRating() const;
    void setRating(double);
    int getMaxListings() const;
    void AddListing(Listing*);
    void UpdateListing(int);
    void DeleteListing(int);
    void viewListings() const;
    static int getTotalSellers();
};

class Buyer:public User {
private:
    FavoriteList* favorites;
    Message* messages[50];
    int messageCount;
    static int total_buyers;
    const int max_favorites;
public:
    Buyer();
    Buyer(int,string,string,string,string);
    Buyer(const Buyer&);
    void search_vehicle(string,int,int);
    void save_to_fav(Listing&);
    void send_mess(Seller&,string);
    void view_fav() const;
    static int getTotalBuyers();
};

class Admin:public User {
private:
    int adminLevel;
    int approvals_done;
    static int total_Admins;
    const string admin_code;
    bool Access;
public:
    Admin();
    Admin(int,string,string,string,string,int,string);
    Admin(const Admin&);
    int getAdminLevel() const;
    int getApprovalsDone() const;
    string getAdminCode() const;
    static int getTotalAdmins();
    void ApproveListing(Listing*);
    void RemoveListing(Listing*);
    void viewAllUsers();
    void viewReports();
};

class MarketPlace {
private:
    Listing* listings[50];
    int listingCount;
    User* users[50];
    int user_count;
    static int total_listings;
public:
    MarketPlace();
    MarketPlace(string);
    MarketPlace(const MarketPlace&);
    int getListingCount() const;
    int getUserCount() const;
    static int getTotalListings();
    void RegisterUser(User*);
    void AddListing(Listing*);
    void SearchVehicle(string,int);
    void DisplayAllListings() const;
};

#endif