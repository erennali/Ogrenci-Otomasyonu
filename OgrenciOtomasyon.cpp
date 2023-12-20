#include <iomanip> 
#include <cstring> 
#include <stdlib.h>
#include <conio.h>
#include <stdio.h> 
#include <fstream>                  
#include <iostream>

using namespace std;

struct Ogrenci
{
	char ad[80];
	char soyad[80];
	char ogr_no[5];
	char cinsiyet;	
};
void OgrenciEkle();
void OgrenciListeleme();
void OgrenciArama();
void OgrenciSil();
void OgrenciDuzenle();
int main(){
	
	char anamenu;
	do{
	system("cls");
	
	cout << "|-------Hosgeldiniz------|" << endl ;
	cout << "|      Secim Yapiniz     |" << endl ;
	cout << "|   1- Ogrenci Ekleme    |" << endl ;
	cout << "|   2- Ogrenci Listeleme |" << endl ;
	cout << "|     3- Ogrenci Arama   |"<< endl;
	cout << "|    4- Ogrenci Sil      |"<< endl;
	cout << "|    5- Ogrenci Duzenle  |"<< endl;
	cout << "|------------------------|" << endl ;
    char secim;
	cin>> secim;
	
	switch(secim) 
	{
		case '1' : 
		{
		OgrenciEkle();
		break;	
		}
		case '2' : 
		{
		 OgrenciListeleme()	;
		 break;
		}
		case '3' : 
		{
		 OgrenciArama()	;
		 break;
		}
		case '4' : 
		{
		 OgrenciSil()	;
		 break;
		}
		case '5' : 
		{
		 OgrenciDuzenle();
		 break;
		}
	}
	
	cout << "Anamenuye Donmek icin: a basin cikmak i�in: c" <<endl ; 
	anamenu=getche();
	
    }while(anamenu=='a');
     

return 0;
}

Ogrenci ogr;

void OgrenciEkle()
{
	ofstream yaz("ogrenci.dat",ios::binary |ios::app);
	char secim;
	int adet=0;
	
	do{
	cout << "Ogrenci Ad Giriniz" << endl;
	cin>> ogr.ad;
	cout << "Ogrenci Soyad Giriniz" << endl;
	cin>> ogr.soyad;
	cout << "Ogrenci No Giriniz" << endl;
	cin>> ogr.ogr_no;
	cout << "Ogrenci Cinsiyet Giriniz (E/K)" << endl;
	ogr.cinsiyet=getche();
	cout << endl;
	yaz.write((char*)&ogr, sizeof(ogr));	
	adet++;	
	cout << "Baska Kayit Eklemek Istermisin (E/H)" << endl;
	secim=getche();
	cout << endl;
	}while(secim=='e' || secim=='E');
	
	cout << adet << " adet Ogrenci Ekledi.." << endl;
	
	yaz.close();
	
	
}

void OgrenciListeleme()
{
	
	ifstream oku("ogrenci.dat",ios::binary |ios::app);
	
	oku.seekg(0,ios::end);
	int kayits=oku.tellg()/sizeof(ogr);
	cout << "Toplam Ogrenci Kayit Sayisi:"<< kayits << endl;
	
	if(kayits>0)
	{
		for(int i=0; i<kayits;i++)
		{
			oku.seekg(i*sizeof(ogr));
			oku.read((char*)&ogr, sizeof(ogr));	
		
			cout << i+1 << ". Ogrencinin Bilgileri"<< endl;
			cout << "Ogrenci Adi: "<< ogr.ad <<endl ;
			cout << "Ogrenci Soyadi: "<< ogr.soyad <<endl ;
			cout << "Ogrenci No: "<< ogr.ogr_no <<endl ;
			if(ogr.cinsiyet=='e' || ogr.cinsiyet=='E')
			cout << "Ogrenci Cinsiyet: ERKEK " <<endl ;
			else if(ogr.cinsiyet=='k' || ogr.cinsiyet=='K')
			cout << "Ogrenci Cinsiyet: KADIN " <<endl ;
			
		}
		
		
	}
	else
	cout << "Kayit Bulunamadi..." << endl;

	oku.close();
}
void OgrenciArama()
{
	
	ifstream oku("ogrenci.dat",ios::binary |ios::app);
	
	oku.seekg(0,ios::end);
	int kayits=oku.tellg()/sizeof(ogr);
//	cout << "Toplam Ogrenci Kayit Sayisi:"<< kayits << endl;

cout <<"Aranan Ogrenci Noyu Giriniz"<< endl;
char ogr_no[80];
cin>> ogr_no;
 		
	if(kayits>0)
	{
		for(int i=0; i<kayits;i++)
		{
			
			oku.seekg(i*sizeof(ogr));
			oku.read((char*)&ogr, sizeof(ogr));
			
			if(strcmp(ogr.ogr_no,ogr_no)==0)
			{
			cout <<  "Bulunan Ogrencinin Bilgileri"<< endl;
			cout << "Ogrenci Adi: "<< ogr.ad <<endl ;
			cout << "Ogrenci Soyadi: "<< ogr.soyad <<endl ;
			cout << "Ogrenci No: "<< ogr.ogr_no <<endl ;
			if(ogr.cinsiyet=='e' || ogr.cinsiyet=='E')
			cout << "Ogrenci Cinsiyet: ERKEK " <<endl ;
			else if(ogr.cinsiyet=='k' || ogr.cinsiyet=='K')
			cout << "Ogrenci Cinsiyet: KADIN " <<endl ;
		    }
		}
		
		
	}
	else
	cout << "Kayit Bulunamadi..." << endl;

	oku.close();
}

void OgrenciSil()
{
	 char ogrno[80];
     char secim= ' ';
     bool var=false;
     
    ifstream oku("ogrenci.dat",ios::binary |ios::app);
	
	oku.seekg(0,ios::end);

	int kayitsayisi=oku.tellg()/sizeof(ogr);
	
     cout<<"Kaydini Sileceginiz Ogrenci No Giriniz : ";
     cin>>ogrno;

     for(int i=0;i<kayitsayisi;i++)
     {
            oku.seekg(i*sizeof(ogr));
			oku.read((char*)&ogr, sizeof(ogr));
			
     if(strcmp(ogr.ogr_no,ogrno)==0)
       {
                 cout<<endl;
                 cout<<"Ogrencinin";
                 cout<<"\nAdi : "<<ogr.ad;
                  cout<<"\nKilo : "<<ogr.soyad<<endl;
                   cout<<"\nYas : "<<ogr.ogr_no;
                 cout<<"\nCinsiyet [E/K]: ";
                 if(ogr.cinsiyet=='e'||ogr.cinsiyet=='E')
                 cout<<"Erkek";
                 if(ogr.cinsiyet=='k'||ogr.cinsiyet=='K')
                 cout<<"Bayan";
                
         	 				  
                cout<<"\n\nSilmek Istediginiz Kayit Bu Mu? [E/H] : ";
                 secim=getche();
            if(secim == 'H' || secim == 'h')
              {      
			    Ogrenci y_ogr;
                ofstream y_dosya("Yedek.dat",ios::app|ios::binary);
                
                strcpy(y_ogr.ad,ogr.ad);
                strcpy(y_ogr.soyad,ogr.soyad);
                strcpy(y_ogr.ogr_no,ogr.ogr_no);
                ogr.cinsiyet=y_ogr.cinsiyet;
                        
                y_dosya.write((char*)&ogr, sizeof(ogr));
                y_dosya.close();
              }
            if(secim=='e'||secim=='E')
              {
   			   	var=true;
  		 	  }
        }
             else
             {
              Ogrenci y_ogr;
              ofstream y_dosya("Yedek.dat",ios::app|ios::binary);
              
              strcpy(y_ogr.ad,ogr.ad);
              strcpy(y_ogr.soyad,ogr.soyad);
              strcpy(y_ogr.ogr_no,ogr.ogr_no);
              ogr.cinsiyet=y_ogr.cinsiyet;
                       
              y_dosya.write((char*)&ogr, sizeof(ogr));
              y_dosya.close();
             }
     }
    oku.close();
    if(var)
    {
               remove("ogrenci.dat");
               rename("Yedek.dat","ogrenci.dat");
               cout<<"\n Kayit Silindi"<<endl;
    }
    else
    {
               remove("Yedek.dat");
               cout<<"\n Kayit Bulunamadi"<<endl;                  
    }
	
	
}

void OgrenciDuzenle()
{
	 char ogrno[80];
     char secim= ' ';
     bool var=false;
     
    ifstream oku("ogrenci.dat",ios::binary |ios::app);
	
	oku.seekg(0,ios::end);

	int kayitsayisi=oku.tellg()/sizeof(ogr);
		
     cout<<"Kaydini Duzelteceginiz No Giriniz : ";
     cin>>ogrno;

     for(int i=0;i<kayitsayisi;i++)
     {
            oku.seekg(i*sizeof(ogr));
			oku.read((char*)&ogr, sizeof(ogr));
			
     		if(strcmp(ogr.ogr_no,ogrno)==0)
     		  {
     		  	
                 cout<<endl;
                 cout<<"Ogrencinin";
                 cout<<"\nAdi : "<<ogr.ad;
                 cout<<"\nSoyad : "<<ogr.soyad<<endl;
                 cout<<"\nOgr No : "<<ogr.ogr_no;
                 cout<<"\nCinsiyet [E/K]: ";
                 if(ogr.cinsiyet=='e'||ogr.cinsiyet=='E')
                 cout<<"Erkek";
                 if(ogr.cinsiyet=='k'||ogr.cinsiyet=='K')
                 cout<<"Bayan";
                 
                  cout<<"\n\nDuzeltmek Istediginiz Kayit Bu Mu? [E/H] : ";
                  secim=getche();
                  if(secim == 'E' || secim == 'e')
                  {
                     	var=true;
                        ofstream dosya("Yedek.dat",ios::app|ios::binary);
                        cout << "\nOgrenci Ad Giriniz" << endl;
						cin>> ogr.ad;
						cout << "Ogrenci Soyad Giriniz" << endl;
						cin>> ogr.soyad;
						cout << "Ogrenci No Giriniz" << endl;
						cin>> ogr.ogr_no;
						cout << "Ogrenci Cinsiyet Giriniz (E/K)" << endl;
						ogr.cinsiyet=getche();
						cout << endl;
		  
                        dosya.write((char*)&ogr, sizeof(ogr));
                        dosya.close();
            	  }
            	 else
                 	{
                         Ogrenci y_ogr;
                         ofstream y_dosya;
                         y_dosya.open("Yedek.dat",ios::app|ios::binary);
                         
                    	 strcpy(y_ogr.ad,ogr.ad);
            			 strcpy(y_ogr.soyad,ogr.soyad);
            			 strcpy(y_ogr.ogr_no,ogr.ogr_no);
             			  y_ogr.cinsiyet=ogr.cinsiyet;
                         
             			 y_dosya.write((char*)&y_ogr, sizeof(y_ogr));
                         y_dosya.close();
                   }
     }
 }
    oku.close();
    if(var)
    {
               remove("ogrenci.dat");
               rename("Yedek.dat","ogrenci.dat");
               cout<<"\nKayit Duzeltildi."<<endl;
    }
    else
    {
               remove("Yedek.dat");
               cout<<"\nKayit Bulunamadi"<<endl;                  
    }

}


