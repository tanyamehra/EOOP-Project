#include <iostream>
#include "Internet.h"

using namespace std;

int main(int argc, char **argv)
{
	Person* John = new Person("John", "Test 1/23, Poland", "127.0.0.1", 30);
	
	cout << John->GetAddress() << endl; // Test 1/23, Poland
	cout << John->GetName() << endl; // John
	cout << John->GetIP() << endl; // 127.0.0.1
	cout << John->GetAge() << endl; // 30
	cout << John->IsAdmin() << endl; // false
	cout << John->IsUser() << endl; // false
	cout << John->IsGuest() << endl; // false
	cout << (*John) << endl; // All of John's data
	
	Website* TestPage = new Website("An arbitrary website", "testpage.com");
	
	cout << TestPage->WebsiteType() << endl; // "Website"
	
	User* JohnUser = TestPage->RegisterUser(John, "john123", "terriblepassword");
	
	cout << (JohnUser == NULL) << endl; // false
	
	cout << JohnUser->IsUser() << endl; // true
	cout << JohnUser->IsAdmin() << endl; // false
	cout << JohnUser->IsGuest() << endl; // false
	cout << JohnUser->GetUsername() << endl; // john123
	cout << JohnUser->IsLoggedIn() << endl; // false
	
	cout << TestPage->LogIn("john123", "aaaaa123") << endl; // false
	cout << JohnUser->IsLoggedIn() << endl; // false
	cout << TestPage->LogIn("john123", "terriblepassword") << endl; // true
	cout << JohnUser->IsLoggedIn() << endl; // true
	cout << TestPage->LogOut("john123") << endl; // true
	cout << TestPage->LogOut("john123") << endl; // false
	cout << JohnUser->IsLoggedIn() << endl; // false
	cout << TestPage->LogIn("john123", "terriblepassword") << endl; // true
	
	Person* Jim = new Person("Jim", "Test 7/13, Poland", "127.0.0.2", 12);
	cout << TestPage->BanIPAddress("127.0.0.2") << endl; // true
	cout << TestPage->BanIPAddress("127.0.0.2") << endl; // false
	User* JimUser = TestPage->RegisterUser(Jim, "jim1", "ngdsg");
	cout << (JimUser == NULL) << endl; // true
	
	Guest* randomGuest = new Guest("Irrelevant", "So is this", "127.0.0.3", 30);
	for (int i = 0; i < 5; i++) TestPage->RegisterGuestVisit(randomGuest);
	cout << TestPage->CountGuestVisits() << endl; // 5
	cout << TestPage->CountGuestVisits(true) << endl; // 1
	
	cout << TestPage->IsUserAdmin(JohnUser) << endl; // false
	Admin* JohnAdmin = TestPage->GrantAdminToUser(JohnUser);
	cout << (JohnAdmin == NULL) << endl; // false
	cout << TestPage->CountAdmins() << endl; // 1
	cout << TestPage->CountUsers() << endl; // 1
	
	cout << TestPage->IsUserAdmin(JohnUser) << endl; // true
	cout << TestPage->IsUserAdmin(JohnAdmin) << endl; // true
	
	cout << TestPage->ClearGuestVisits() << endl; // 5
	cout << TestPage->RemoveAllUsers(false) << endl; // 0
	cout << TestPage->RemoveAllUsers(true) << endl; // 1
	
	// We know the pointers to JohnUser and JohnAdmin are no longer valid, so we better set them to null
	// This protects us if we forget to keep track
	JohnUser = NULL;
	JohnAdmin = NULL;
	
	// Printing test
	cout << TestPage->GetAddress() << endl; // testpage.com
	cout << TestPage->GetDescription() << endl; // An arbitrary website
	cout << TestPage->GetCreationTime() << endl; // Should print the system time at the moment of creation
	
	cout << TestPage->UnBanIPAddress("127.0.0.2") << endl; // true
	cout << TestPage->UnBanIPAddress("127.0.0.2") << endl; // false
	JimUser = TestPage->RegisterUser(Jim, "jim1", "ngdsg");
	cout << (JimUser == NULL) << endl; // false
	
	cout << TestPage->LogIn("jim1", "ngdsg") << endl; // true
	cout << TestPage->CheckReadPermissions(JimUser) << endl; // 1
	cout << TestPage->CheckWritePermissions(JimUser) << endl; // 1
	cout << TestPage->CheckReadPermissions(randomGuest) << endl; // 1
	cout << TestPage->CheckWritePermissions(randomGuest) << endl; // 0
	
	Post* TestPost = TestPage->CreatePost("Lorem ipsum", "Dolor sit amet...", JohnUser, false);
	cout << (TestPost == NULL) << endl; // true
	TestPost = TestPage->CreatePost("Lorem ipsum", "Dolor sit amet...", JimUser, false);
	cout << (TestPost == NULL) << endl; // false
	
	cout << (*TestPost) << endl; // Should print the post
	cout << (*TestPage) << endl; // Should print the website and have it contain the post
	
	cout << TestPost->EditPost("Ipsum lorem", "Dolor sit amet.", JimUser) << endl; // true
	
	cout << (*TestPost) << endl; // Should print the edited post (Ipsum lorem)
	cout << (*TestPage) << endl; // Should print the website and have it contain the edited post
	
	User* JimUserDuplicate = TestPage->RegisterUser(Jim, "jim1", "ngdsg");
	cout << (JimUserDuplicate == NULL) << endl; // true
	
	JimUserDuplicate = TestPage->RegisterUser(Jim, "jim2", "ngdsg");
	cout << (JimUserDuplicate == NULL) << endl; // false
	
	cout << TestPost->ReadPost(Jim) << endl; // true
	cout << TestPost->ReadPost(Jim) << endl; // true
	cout << TestPost->ReadPost(Jim) << endl; // true
	
	cout << TestPost->CountViews() << endl; // 3
	cout << TestPost->CountViews(true) << endl; // 1
	
	Fan* fan1 = new Fan("Fan1", "Fancity, Fanland", "127.0.0.3", 18);
	Fan* fan2 = new Fan("Fan2", "Fancity, Fanland", "127.0.0.3", 18);
	Fan* fan3 = new Fan("Fan3", "Fancity, Fanland", "127.0.0.3", 18);
	
	Fanpage* fp1 = new Fanpage("Yet Another Garage Band", "fb.com/yagb");
	Fanpage* fp2 = new Fanpage("Daily Memes", "fb.com/lol");
	cout << fan1->LikeFanpage(fp1) << endl; // true
	cout << fan1->LikeFanpage(fp1) << endl; // false
	cout << fan2->LikeFanpage(fp1) << endl; // true
	cout << fan3->LikeFanpage(fp1) << endl; // true
	
	cout << fan1->LikeFanpage(fp2) << endl; // true
	
	cout << fan1->CountLikedFanpages() << endl; // 2
	cout << fan2->CountLikedFanpages() << endl; // 1
	cout << fan3->CountLikedFanpages() << endl; // 1
	
	cout << fp1->CountLikes() << endl; // 3
	cout << fp2->CountLikes() << endl; // 1
	
	cout << fan1->UnLikeFanpage(fp2) << endl; // true
	cout << fan1->UnLikeFanpage(fp2) << endl; // false
	
	cout << fp2->CountLikes() << endl; // 0
	
	Person* Jinny = new Person("Jinny", "Chicago, Illinois, USA", "127.0.0.4", 19);
	
	Blog* TestBlog = new Blog("Another Fashion Blog", "lookatme.com", Jinny);
	cout << TestBlog->CountAdmins() << endl; // 1 (created by default)
	Admin* JinnyAdmin = TestBlog->GetAdmin(0);
	cout << (JinnyAdmin == NULL) << endl; // false
	cout << JinnyAdmin->GetName() << endl; // "Jinny"
	
	User* user1 = TestBlog->RegisterUser(fan1, "abc", "xyz");
	cout << (user1 == NULL) << endl; // false
	
	Admin* admin1 = TestBlog->GrantAdminToUser(user1);
	cout << (admin1 == NULL) << endl; // true
	Admin* admin0 = TestBlog->GrantAdminToUser(NULL);
	cout << (admin0 == NULL) << endl; // true
	
	cout << TestBlog->CheckReadPermissions(randomGuest) << endl; // 1
	cout << TestBlog->CheckWritePermissions(randomGuest) << endl; // 0
	cout << TestBlog->CheckReadPermissions(user1) << endl; // 1
	cout << TestBlog->CheckWritePermissions(user1) << endl; // 0
	
	cout << TestBlog->CheckReadPermissions(Jinny) << endl; // 1
	cout << TestBlog->CheckWritePermissions(Jinny) << endl; // 1
	
	Person* Writer1 = new Person("Jack", "irrelevant", "127.0.0.5", 30);
	Person* Writer2 = new Person("Zach", "irrelevant", "127.0.0.6", 30);
	Person* Writer3 = new Person("Hugh", "irrelevant", "127.0.0.7", 30);
	
	NewsPortal* xyz = new NewsPortal("XYZ News", "xyz.co.uk");
	User* WriterUser1 = xyz->RegisterUser(Writer1, "writer1", "pwd1");
	User* WriterUser2 = xyz->RegisterUser(Writer2, "writer2", "pwd2");
	User* WriterUser3 = xyz->RegisterUser(Writer3, "writer3", "pwd3");
	cout << (WriterUser1 == NULL || WriterUser2 == NULL || WriterUser3 == NULL) << endl; // false
	
	xyz->LogIn("writer1", "pwd1");
	xyz->LogIn("writer2", "pwd2");
	xyz->LogIn("writer3", "pwd3");
	
	Admin* WriterAdmin = xyz->GrantAdminToUser(WriterUser1);
	cout << (WriterAdmin == NULL) << endl; // false
	
	xyz->CreatePost("Something something the Royal Family", "...", WriterUser1, false);
	xyz->CreatePost("Cure for cancer found", "...", WriterUser2, false);
	xyz->CreatePost("US scientists prove that 2+2=3.9 for really small 2's", "...", WriterUser3, false);
	
	Post* NewsPost1 = xyz->GetPost(0);
	Post* NewsPost2 = xyz->GetPost(1);
	Post* NewsPost3 = xyz->GetPost(2);
	
	xyz->RegisterGuestVisit(randomGuest);
	xyz->RegisterGuestVisit(randomGuest);
	
	cout << xyz->SetMainHeadline(NewsPost1, WriterUser2) << endl; // false
	cout << xyz->SetMainHeadline(NewsPost1, WriterAdmin) << endl; // true
	
	xyz->RegisterGuestVisit(randomGuest);
	xyz->RegisterGuestVisit(randomGuest);
	xyz->RegisterGuestVisit(randomGuest);
	
	cout << NewsPost1->CountViews() << endl; // 3
	cout << NewsPost2->CountViews() << endl; // 0
	cout << NewsPost3->CountViews() << endl; // 0
	
	Person* Mark = new Person("Mark", "Wall Street", "127.0.0.8", 40);
	CompanyWebsite* AcquisitionINC = new CompanyWebsite("Acquisition Incorporated - Integrity, Intelligence", "acqinc.com", "Acquisition Incorporated", "Wall Street", "1-800-12-34, info@acqinc.com");
	
	cout << (*AcquisitionINC) << endl; // Should present the company's data
	User* MarkUser = AcquisitionINC->RegisterUser(Mark, "mark", "xHz%@#4gS");
	AcquisitionINC->LogIn("mark", "xHz%@#4gS");
	
	cout << AcquisitionINC->UpdateCompanyData("Acquisition", "Finland", "123-456-789, info@acqinc.com", MarkUser) << endl; // false
	
	cout << (*AcquisitionINC) << endl; // Should present the company's old data
	
	Admin* MarkAdmin = AcquisitionINC->GrantAdminToUser(MarkUser);
	
	cout << AcquisitionINC->UpdateCompanyData("Acquisition", "Finland", "123-456-789, info@acqinc.com", MarkAdmin) << endl; // true
	
	cout << (*AcquisitionINC) << endl; // Should present the company's updated data
	
	cout << (AcquisitionINC->CreatePost("a", "b", MarkAdmin, false) == NULL) << endl; // true
	
	// Put everything into the Internet for easier access
	Internet& net = Internet::GetInternet();
	
	// Should work with single argument
	net << *John;
	net << *TestPage;
	
	// And with multiple ones
	net << *Jim << *randomGuest << *fan1 << *fan2 << *fan3 << *Jinny << *Writer1 << *Writer2 << *Writer3;
	net << *fp1 << *fp2 << *TestBlog;
	
	// Also of mixed type
	net << *xyz << *Mark << *AcquisitionINC;
	
	net.PrintAllPeople(); // Should print all the people in the order they were added
	net.PrintAllWebsites(); // Should print all websites (address, description and type) in the order they were added
	
	net >> *Mark >> *AcquisitionINC;
	
	net.PrintAllPeople(); // Should print all the people sans Mark
	net.PrintAllWebsites(); // Should print all websites sans Acq Inc
	
	delete AcquisitionINC;
	delete Mark;
	
	net.Clear();
}
