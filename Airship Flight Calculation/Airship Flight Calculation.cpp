// Airship Flight Calculation.cpp : This file contains the 'main' function. Program execution begins and ends there.


#include <iostream>
#include<cmath>
using namespace std;


int main()
{
	// Set Temp and Pressure values
	float P_atm, T_atm;
	cout << "Enter Atmospheric Pressure Value in N/m^2\n";
	cin >> P_atm;
	cout << " Enter Temperature Value in K\n";
	cin >> T_atm;


   //  Universal Gas Constant for Helium R_He=Cp-Cv

	float Cp, Cv, R_He, Rho_He, K_He, Rho_air, Rho_Pure_He;
 
	cout << "Enter Cp & Cv Values for Helium in J/KgK\n";
	cin >> Cp >> Cv;

	
	R_He = Cp - Cv;

	cout << " R_He is: " << R_He << "J/KgK" << endl;

	// Density of Helium

	Rho_He = (P_atm / (R_He * T_atm)) / 1000;

	cout << "The density of Helium at given condition is: " << Rho_He << endl;

	// Calculating for Pure Helium with impurity factor,

	cout << "Enter value of Impurity Factor\n";
	cin >> K_He;
	cout << "Enter Air Density at Altitude in Kg/m^3\n";
	cin >> Rho_air;

	Rho_Pure_He = (Rho_He * K_He) + (Rho_air * (1 - K_He));

	cout << "Density of Pure Helium is: " << Rho_Pure_He << "Kg/m^3" << endl;

	// Mass fraction consideration, entering weights of Payload, Structure and Propulsion System and additinal weight,

	float M_str, M_pro, M_pay, M_add, M_Total=0.00, M_Total_1, M_Fos;

	cout << "Enter Structural Mass in Kg\n";
	cin >> M_str;
	cout << "Enter Propulsion System Mass in Kg\n";
	cin >> M_pro;
	cout << "Enter Payload mass if any in Kg\n";
	cin >> M_pay;
	cout <<"Enter Additional mass if any in Kg\n";
	cin >> M_add;

	M_Total_1 = M_str + M_pro + M_pay + M_add;

	cout << " Overall Mass of Airship is: " << M_Total_1 << endl;

	cout << " Enter the FOS value for Mass\n";
	cin >> M_Fos;

	if (M_Fos > 0) {

		M_Total = M_Fos * M_Total_1;

	}
	else {

		M_Total = M_Total_1;
	}

	cout << "Total Mass of Airship with FOS is: " << M_Total << "Kg"<<endl;

	// Volume of Airship will be 

	float Mass_He, Vol_He;

	Vol_He= M_Total / (Rho_air - Rho_Pure_He);

	cout << " Hence Volume of Airship Required will be: " << Vol_He << "m^3" << endl;


	// Hence mass of He required just to lift the airship will be, Density= Mass/Volume,

	Mass_He = Vol_He * Rho_Pure_He;

	cout << " Therefore " << Mass_He << " Kg of is Helium required to just lift the Airship "<<endl;

	// Buoyancy Force

	float F_Buyo, g = 9.81;

	F_Buyo = (Rho_air - Rho_Pure_He) * Vol_He * g;
	cout << "Therefore, Buoyancy Force is " << F_Buyo << " N" << std::endl;

	// Drag Calculation,

	float Cd, F_Drag,S, Vel_max,l,Myu,Re;

	cout << "Enter Co-Efficient of Drag Value" << endl;
	cin >> Cd;

	cout << "Enter Surface Area of Airship" << endl;
	cin >> S;

	cout << "Enter Maximum Airship Velocity in m/s\n";
	cin >> Vel_max;

	F_Drag = Cd * 0.5 * Rho_air * Vel_max * Vel_max * S;
	

	cout << "Estimated Drag force is: " << F_Drag << "N"<<endl;



// Motor Calculation

	float Thrust, FOS, Eeta_Prop, Power_Motor, Power_Output, Power_Cruise, Vel_air;

	cout << " Enter Factor of Safety\n";
	cin >> FOS;
	cout << "Enter Propeller Efficiency\n";
	cin >> Eeta_Prop;


	Thrust = F_Drag * FOS;

	cout << "Therefore required Thrust will be: " << Thrust << "N"<< endl;

	Power_Motor = (Thrust * Vel_max) / (Eeta_Prop);

	cout << " Power requirement will be " << Power_Motor<<"W" << endl;


	cout << "Enter Maximum Power output of motors\n";
	cin >> Power_Output;

	cout << "Enter Gust Velocity" << endl;
	cin >> Vel_air;

	Power_Cruise = (Vel_air / Vel_max) * Power_Output;

	cout << " Hence in order to stay stationary while opposing incoming gust Minimum of " << Power_Cruise << " W of Power will be required"<<endl;


	return(0);

	
}






