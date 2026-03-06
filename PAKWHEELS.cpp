#include "PakWheels.h"

    User::User():userID(0),name(""),email(""),phone(""),password(""),role("User"){}
User::User(int id,string n,string e,string p,string pass):userID(id),name(n),email(e),phone(p),password(pass),role("User"){}
User::User(const User& u):userID(u.userID),name(u.name),email(u.email),phone(u.phone),password(u.password),role(u.role){}
string User::getName() const{return name;}
string User::getEmail() const{return email;}
string User::getPhone() const{return phone;}
int User::getUserID() const{return userID;}
string User::getRole() const{return role;}
    void User::setPhone(string p){phone=p;}
    void User::setPassword(string p){password=p;}
    void User::Login(string e,string p){
        if(email==e && password==p){
            cout<<"Login Successful"<<endl; }
        else cout<<"Invalid Credentials"<<endl;}
    void User::Logout(){
        cout<<name<<" Logged out"<<endl;}
    void User::UpdateProfile(string n,string p){
        name=n; phone=p;}
    void User::DisplayProf() const{
        cout<<"ID:"<<userID<<" Name:"<<name<<" Email:"<<email<<" Phone:"<<phone<<" Role:"<<role<<endl;
    }

Vehicle::Vehicle():brand(""),model(""),year(0),price(0),mileage(0){}
	Vehicle::Vehicle(string b,string m,int y,double p,double mil):
		brand(b),model(m),year(y),price(p),mileage(mil){}
	Vehicle::Vehicle(const Vehicle& v):
		brand(v.brand),model(v.model),year(v.year),price(v.price),mileage(v.mileage){}
	string Vehicle::getBrand() const{return brand;}
	string Vehicle::getModel() const{return model;}
	int Vehicle::getYear() const{return year;}
	double Vehicle::getPrice() const{return price;}
	double Vehicle::getMileage() const{return mileage;}
	void Vehicle::setPrice(double p){price=p;}
	void Vehicle::Display() const{
    	cout<<"Brand: "<<brand<<"\n"<<"Model: "<<model<<"\n"<<"Year: "<<year<<"\n"<<"Price:"<<price<<"\n"<<"Mileage: "<<mileage<<endl;
	}
	void Vehicle::UpdatePrice(double new_price){
    	price=new_price;}
	double Vehicle::CalculateDepreciation(){
    	return price-(price*0.05*(2025-year));}
	bool Vehicle::MatchFilter(string b,double min,double max) const{
    	return brand==b && price>=min && price<=max;
	}

Car::Car():Vehicle(),fuelType(""),transmission(""),engine_capacity(0),body_type(""),registered(false){}
	Car::Car(string b,string m,int y,double p,double mil,string f,string t,int e,string body,bool r)
		:Vehicle(b,m,y,p,mil),fuelType(f),transmission(t),engine_capacity(e),body_type(body),registered(r){}
	Car::Car(const Car& c):
		Vehicle(c),fuelType(c.fuelType),transmission(c.transmission),engine_capacity(c.engine_capacity),body_type(c.body_type),registered(c.registered){}
	string Car::getFuelType() const{return fuelType;}
	string Car::getTransmission() const{return transmission;}
	int Car::getEngineCapacity() const{return engine_capacity;}
	string Car::getBodyType() const{return body_type;}
	bool Car::getRegistrationStatus() const{return registered;}
	void Car::Display() const{
    	Vehicle::Display();
     	cout<<"Fuel: "<<fuelType<<"	Trans: "<<transmission<<"	Engine: "<<engine_capacity<<"	Body: "<<body_type<<"	Registered: "<<registered<<endl;
		 }	
	void Car::updateRegis(bool status){registered=status;}
	void Car::CalculateTax(){
    	cout<<"Tax:"<<engine_capacity*0.02<<endl;}
	void Car::showSpecs() const{Display();
	}

Listing::Listing():listing_id(0),seller(nullptr),Approve(false),Description(""){}
	Listing::Listing(int id,const Car& car,Seller* s,string d):
		listing_id(id),car_details(car),seller(s),Approve(false),Description(d){}
	Listing::Listing(const Listing& l):
		listing_id(l.listing_id),car_details(l.car_details),seller(l.seller),Approve(l.Approve),Description(l.Description){}
	int Listing::getListingID() const{return listing_id;}
	bool Listing::getApprovalStatus() const{return Approve;}
	string Listing::getDescription() const{return Description;}
	Seller* Listing::getSeller() const{return seller;}
	Car Listing::getCarDetails() const{return car_details;}
	void Listing::DisplayListing() const{
    	cout<<"Listing:"<<listing_id<<"\n"<<"Approved:"<<Approve<<"\n"<<"Desc:"<<Description<<endl; 
    	car_details.Display();
    	cout<<endl;
	}
	void Listing::markApprove(){Approve=true;}
	void Listing::markUnApprove(){Approve=false;}
	void Listing::UpdateDescription(string d){Description=d;}


FavoriteList::FavoriteList():count(0),maxSize(50),listId(0),create_date("NA"){}
	FavoriteList::FavoriteList(int id,string date):
		count(0),maxSize(50),listId(id),create_date(date){}
	FavoriteList::FavoriteList(const FavoriteList& f):
		count(f.count),maxSize(50),listId(f.listId),create_date(f.create_date){
    	for(int i=0;i<count;i++) listings[i]=f.listings[i];}
	int FavoriteList::getCount() const{return count;}
	int FavoriteList::getMaxSize() const{return maxSize;}
	int FavoriteList::getListID() const{return listId;}
	string FavoriteList::getCreatedDate() const{return create_date;}
	void FavoriteList::AddToFav(Listing* l){
	    if(count<maxSize) listings[count++]=l;}
	void FavoriteList::RemoveFav(int id){
    	for(int i=0;i<count;i++){
        	if(listings[i]->getListingID()==id){
            	for(int j=i;j<count-1;j++) listings[j]=listings[j+1]; 
            	count--; 
           		return;}
        }
    }
	void FavoriteList::DisplayFav() const{
    	for(int i=0;i<count;i++) listings[i]->DisplayListing();}
	bool FavoriteList::isFull() const{return count>=maxSize;
	}


Message::Message():msgId(0),Sender(nullptr),Receiver(nullptr),time_stamp("NA"){}
	Message::Message(int id,string c,Buyer* s,Seller* r,string t):
		msgId(id),content(c),Sender(s),Receiver(r),time_stamp(t){}
	Message::Message(const Message& m):
		msgId(m.msgId),content(m.content),Sender(m.Sender),Receiver(m.Receiver),time_stamp(m.time_stamp){}
	int Message::getMessageID() const{return msgId;}
	string Message::getContent() const{return content;}
	string Message::getTimestamp() const{return time_stamp;}
	Buyer* Message::getSender() const{return Sender;}
	Seller* Message::getReceiver() const{return Receiver;}
	void Message::SendMsg(){
    	cout<<"Message Sent:"<<content<<endl;}
	void Message::DisplayMsg() const{
    	cout<<msgId<<" "<<content<<endl;}
	void Message::deleteMsg(){content="";}
	void Message::MarkRead(){
    	cout<<"Read"<<endl;
	}


	int Seller::totalSellers=0;
	Seller::Seller():User(),listingCount(0),maxListings(100),rating(0){totalSellers++;}
	Seller::Seller(int id,string n,string e,string p,string pass,double r):
		User(id,n,e,p,pass),listingCount(0),maxListings(100),rating(r){totalSellers++;}
	Seller::Seller(const Seller& s):User(s),listingCount(s.listingCount),maxListings(100),rating(s.rating){
	    for(int i=0;i<listingCount;i++) listings[i]=s.listings[i]; totalSellers++;
	}
	int Seller::getListingCount() const{return listingCount;}
	double Seller::getRating() const{return rating;}
	void Seller::setRating(double r){rating=r;}
	int Seller::getMaxListings() const{return maxListings;}
	void Seller::AddListing(Listing* l){
    	if(listingCount<maxListings) listings[listingCount++]=l;
	}
	void Seller::UpdateListing(int id){
    	for(int i=0;i<listingCount;i++){
        	if(listings[i]->getListingID()==id){
            	listings[i]->UpdateDescription("Updated");
        	}
    	}
	}
	void Seller::DeleteListing(int id){
    	for(int i=0;i<listingCount;i++){
        	if(listings[i]->getListingID()==id){
            	for(int j=i;j<listingCount-1;j++) listings[j]=listings[j+1];
            	listingCount--; 
            	return;}
    	}
	}
	void Seller::viewListings() const{
    	for(int i=0;i<listingCount;i++) listings[i]->DisplayListing();
	}
	int Seller::getTotalSellers(){return totalSellers;}


int Buyer::total_buyers=0;
	Buyer::Buyer():User(),messageCount(0),max_favorites(20){
    	favorites=new FavoriteList(); total_buyers++;
	}
	Buyer::Buyer(int id,string n,string e,string p,string pass):User(id,n,e,p,pass),messageCount(0),max_favorites(20){
    	favorites=new FavoriteList(); total_buyers++;
	}
	Buyer::Buyer(const Buyer& b):User(b),messageCount(b.messageCount),max_favorites(20){
    	favorites=new FavoriteList(*b.favorites); 
    	for(int i=0;i<messageCount;i++) messages[i]=b.messages[i]; 
    	total_buyers++;
	}
	void Buyer::search_vehicle(string brand,int min_price,int max_price){
    	cout<<"Searching:"<<brand<<" Price:"<<min_price<<"-"<<max_price<<endl;
	}
	void Buyer::save_to_fav(Listing &l){favorites->AddToFav(&l);}
	void Buyer::send_mess(Seller &s,string content){
    	if(messageCount<50){
        	messages[messageCount]=new Message(messageCount+1,content,this,&s,"Now");
        	messages[messageCount]->SendMsg(); 
        	messageCount++;
    	}
	}
	void Buyer::view_fav() const{favorites->DisplayFav();}
	int Buyer::getTotalBuyers(){return total_buyers;}


int Admin::total_Admins=0;
	Admin::Admin():User(),adminLevel(1),approvals_done(0),admin_code("ADM001"),Access(true){total_Admins++;}
	Admin::Admin(int id,string n,string e,string p,string pass,int lvl,string code):
		User(id,n,e,p,pass),adminLevel(lvl),approvals_done(0),admin_code(code),Access(true){total_Admins++;}
	Admin::Admin(const Admin& a):
		User(a),adminLevel(a.adminLevel),approvals_done(a.approvals_done),admin_code(a.admin_code),Access(a.Access){total_Admins++;}
	int Admin::getAdminLevel() const{return adminLevel;}
	int Admin::getApprovalsDone() const{return approvals_done;}
	string Admin::getAdminCode() const{return admin_code;}
	int Admin::getTotalAdmins(){return total_Admins;}
	void Admin::ApproveListing(Listing* l){l->markApprove(); approvals_done++;}
	void Admin::RemoveListing(Listing* l){l->markUnApprove();}
	void Admin::viewAllUsers(){
	    cout<<"Viewing Users"<<endl;
	}
	void Admin::viewReports(){
    	cout<<"Viewing Reports"<<endl;
	}


	int MarketPlace::total_listings=0;
	MarketPlace::MarketPlace():listingCount(0),user_count(0){}
	MarketPlace::MarketPlace(string name):listingCount(0),user_count(0){}
	MarketPlace::MarketPlace(const MarketPlace& m):listingCount(m.listingCount),user_count(m.user_count){
	    for(int i=0;i<listingCount;i++) listings[i]=m.listings[i]; 
    	for(int i=0;i<user_count;i++) users[i]=m.users[i];
	}
	int MarketPlace::getListingCount() const{return listingCount;}
	int MarketPlace::getUserCount() const{return user_count;}
	int MarketPlace::getTotalListings(){return total_listings;}
	void MarketPlace::RegisterUser(User* u){
    	if(user_count<50) users[user_count++]=u;
	}
	void MarketPlace::AddListing(Listing* l){
    	if(listingCount<50){
        	listings[listingCount++]=l; 
        	total_listings++;
    	}
	}
	void MarketPlace::SearchVehicle(string brand,int year){
    	for(int i=0;i<listingCount;i++){
        	if(listings[i]->getCarDetails().getBrand()==brand && listings[i]->getCarDetails().getYear()==year){
            	listings[i]->DisplayListing();
        	}
    	}
	}
	void MarketPlace::DisplayAllListings() const{
    	for(int i=0;i<listingCount;i++) listings[i]->DisplayListing();
	}


int main(){
    MarketPlace market("PakWheels");
    Admin admin1(1,"Mahandar","admin@pakwheels.com","03002323233","admin123",2,"ADM100");
    market.RegisterUser(&admin1);
    Seller seller1(2,"Jatin","jatin@gmail.com","03001112222","jatin123",4.5);
    market.RegisterUser(&seller1);
    Buyer buyer1(3,"Chetan","chetan@gmail.com","03002222112","chetan123");
    market.RegisterUser(&buyer1);
    Car car1("Toyota","Corolla",2020,3500000,45000,"Petrol","Automatic",1600,"Sedan",true);
    Car car2("Honda","Civic",2019,3300000,50000,"Petrol","Manual",1800,"Sedan",true);
    Listing l1(101,car1,&seller1,"Very Good condition");
    Listing l2(102,car2,&seller1,"Single owner");
    seller1.AddListing(&l1); 
    seller1.AddListing(&l2);
    market.AddListing(&l1);
    market.AddListing(&l2);
    admin1.ApproveListing(&l1); 
    admin1.ApproveListing(&l2);
    market.DisplayAllListings();
    market.SearchVehicle("Toyota",2020);
    buyer1.save_to_fav(l1);
    buyer1.view_fav();
    buyer1.send_mess(seller1,"Is price negotiable?");
    seller1.viewListings();
    buyer1.DisplayProf();
    seller1.DisplayProf();
    cout<<"Total Sellers:"<<Seller::getTotalSellers()<<endl;
    cout<<"Total Buyers:"<<Buyer::getTotalBuyers()<<endl;
    cout<<"Total Admins:"<<Admin::getTotalAdmins()<<endl;
    cout<<"Total Listings:"<<MarketPlace::getTotalListings()<<endl;
}