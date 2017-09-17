#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

// functions declarations
int plan_near (int UNITS_PER_CAN, int plant_count );
int plan_far(int UNITS_PER_CAN, int plant_count);
int plan_near_first_trip(int UNITS_PER_CAN, int plant_count, int &i, int &save_current_plant, int &save_cum_steps, int &save_cum_step_units,int &trip);
int plan_near_rest_trips(int UNITS_PER_CAN, int plant_count,int &i,int &save_current_plant, int &save_cum_steps, int &save_cum_step_units,int &trip);
int plan_far_first_trip(int UNITS_PER_CAN, int &k, int plant_count,int &save_current_plant, int &save_cum_steps, int &save_cum_step_units, int &trip);
int plan_far_rest_trips(int UNITS_PER_CAN, int &k, int plant_count,int &save_current_plant, int &save_cum_steps, int &save_cum_step_units,int &trip);
void plan_is_better(int temp1, int temp2, int plant_count);


int main()
{
    const int UNITS_PER_CAN = 3; 										// filled CAN capacity
    const string INPUT_FILE_NAME = "counts.txt";							// file with the input
    int plant_count;														// variable to store input value from input file

    // display error if issue with opening file or if file is not present
    ifstream input;
    input.open(INPUT_FILE_NAME);
    if (input.fail())
    {
        cout << "Failed to open " << INPUT_FILE_NAME << endl;
        return -1;
    }

    // Loop once for each number of plants read from the input file.
    // Stop when the number of plants is 0 or less.
    // During each loop, simulate Plan Near and Plan Far.
    do
    {
        input >> plant_count;

        if (plant_count <= 0) return 0;									// if plant is '0' end the loop.

        int temp1 = plan_near( UNITS_PER_CAN,  plant_count);				// Plan for Near Plant

        	cout << endl;

        int temp2 =	plan_far( UNITS_PER_CAN,  plant_count);				// Plan for Far Plant

       	// Which plan is better? Better means fewer step-units.
        // determining better plan

        plan_is_better(temp1, temp2, plant_count);						//Checking which plan is better

    } while (plant_count > 0);

    return 0;
}

//function definitions


int plan_near(int UNITS_PER_CAN, int plant_count)
{
	int trip = 0;
	int save_current_plant = 0;
	int save_cum_steps = 0;
	int save_cum_step_units = 0;
	int temp1 = 0;

	cout << endl;
	cout << "==========================" << endl;
	cout << " Plan Near with " << plant_count << " plants" << endl;
	cout << "==========================" << endl;
	cout << endl;
	cout << "Where      Cum. steps  Water amt.  Cum. step-units" << endl;
	cout << "---------  ----------  ----------  ---------------" << endl;

	// a trip = starting from 1st plant and ending to the faucet
	// select based on initial trip or not
	// in case of initial trips variables needs to be initialised differently as compared to other trips

	for ( int i = 1 ; i <= plant_count ; i )
        	{
			if ( trip == 0 )
				temp1 = plan_near_first_trip ( UNITS_PER_CAN,  plant_count, i, save_current_plant, save_cum_steps, save_cum_step_units, trip);
			else
        			temp1 = plan_near_rest_trips(UNITS_PER_CAN,  plant_count, i, save_current_plant, save_cum_steps, save_cum_step_units, trip);
        	}

	return temp1;
}


int plan_near_first_trip (int UNITS_PER_CAN, int plant_count, int &i, int &save_current_plant, int &save_cum_steps, int &save_cum_step_units, int &trip)
{
	//initialize variables for initial trip
	int water_in_can = 0;
	int cum_steps = 0, cum_step_units = 0;
	int current_plant = 0;
	int temp1;

	//untill water in can is not equal to zero or plant count is not reached run the loop
	for ( water_in_can = UNITS_PER_CAN ; water_in_can > 0 && i <= plant_count ; water_in_can -- , i ++)
	{
    		current_plant = current_plant + 1;
	    	cum_steps = cum_steps + 1;
	    	cum_step_units = cum_step_units + water_in_can;

	    	cout << "Plant " << current_plant << '\t' ;
	   	cout << "	" << cum_steps << '\t' ;
	    cout << "	" << water_in_can << '\t' ;
	    cout << "	" << cum_step_units << endl;

	 }

	 // saving variable values to pass to next trip for processing.
	 if ( water_in_can == 0)
	 {
	    save_current_plant = current_plant;
	    save_cum_steps	= cum_steps + 2*current_plant;
	    save_cum_step_units = cum_step_units + UNITS_PER_CAN*save_current_plant;
	    trip = trip +1;
	 }

	 cum_steps = cum_steps + current_plant;
	 cum_step_units = cum_step_units + water_in_can*current_plant;
	 current_plant = 0;

	 cout << "FAUCET " << '\t' ;
	 cout << "	" << cum_steps << '\t' ;
	 cout << "	" << water_in_can << '\t' ;
	 cout << "	" << cum_step_units << endl;

	 if ( i == plant_count + 1 )
	 {
		 cout << endl << "Plan Near: Total Steps = " << cum_steps << ", total step-units = " << cum_step_units  << endl;
		 temp1 = cum_step_units;
	  }

	 // return cum step units to compare with that of the "PLan far" results
	 return temp1;
}


int plan_near_rest_trips(int UNITS_PER_CAN, int plant_count,int &i,int &save_current_plant, int &save_cum_steps, int &save_cum_step_units,int &trip )
{

	int water_in_can ;
	int temp1;
	for ( water_in_can = UNITS_PER_CAN ;  water_in_can > 0 && i <= plant_count ; water_in_can -- , i ++)
	{
		// use saved varibale values from first trip to continue with the rest trips
		save_current_plant = save_current_plant + 1;
		save_cum_steps = save_cum_steps + 1;
	    	save_cum_step_units = save_cum_step_units + water_in_can;

	    	cout << "Plant " << save_current_plant << '\t' ;
	    	cout << "	" << save_cum_steps << '\t' ;
	    	cout << "	" << water_in_can << '\t' ;
	    	cout << "	" << save_cum_step_units << endl;
	}

	save_cum_steps	= save_cum_steps + save_current_plant;
	save_cum_step_units = save_cum_step_units + water_in_can*save_current_plant;

	cout << "FAUCET " << '\t' ;
	cout << "	" << save_cum_steps << '\t' ;
	cout << "	" << water_in_can << '\t' ;
	cout << "	" << save_cum_step_units << endl;

	if ( i == plant_count + 1)
	{
		cout << endl << "Plan Near: Total Steps = " << save_cum_steps << ", total step-units = " << save_cum_step_units  << endl;
	 	//cout << "==========================" << endl;
		temp1 = save_cum_step_units;
	}

	save_cum_steps	= save_cum_steps + save_current_plant;
	save_cum_step_units = save_cum_step_units + UNITS_PER_CAN*save_current_plant;
	trip = trip +1;

	// return cum step units to compare with that of the "PLan far" results
	return temp1;
}


int plan_far (int UNITS_PER_CAN, int plant_count)
{
	int trip = 0;
	int save_current_plant =0;
	int save_cum_steps = 0;
	int save_cum_step_units =0;
	int temp2 =0;

	cout << "==========================" << endl;
	cout << " Plan Far with " << plant_count << " plants" << endl;
	cout << "==========================" << endl;
	cout << endl;
	cout << "Where      Cum. steps  Water amt.  Cum. step-units" << endl;
	cout << "---------  ----------  ----------  ---------------" << endl;

	// a trip = starting from the plant and ending to the faucet
	// select based on first trip or not
	// in case of first trip variables needs to be initialised differently as compared to other trips

	for ( int k = plant_count ; k > 0 ; k )
	{
		if ( trip == 0 )
			temp2 = plan_far_first_trip( UNITS_PER_CAN,  k,  plant_count, save_current_plant, save_cum_steps, save_cum_step_units, trip);
		else
			temp2 = plan_far_rest_trips(UNITS_PER_CAN,  k,  plant_count, save_current_plant, save_cum_steps, save_cum_step_units, trip);
	}

	return temp2;
}


int plan_far_first_trip(int UNITS_PER_CAN, int &k, int plant_count,int &save_current_plant, int &save_cum_steps, int &save_cum_step_units,int &trip)
{
	// Initialize variables for plan far
	int water_in_can;
	int cum_step_units = UNITS_PER_CAN*k;
	int cum_steps = k ;
	int current_plant ;
	int temp2;

	// run loop until water in can is zero or plant is zero
	for ( water_in_can = UNITS_PER_CAN ; water_in_can > 0 && k > 0 ; water_in_can )
	{
		cout << "Plant " << k << '\t' ;
	    	cout << "	" << cum_steps << '\t' ;
	    	cout << "	" << water_in_can << '\t' ;
	    	cout << "	" << cum_step_units << endl;
	    	k--;
	    	water_in_can--;
	    current_plant = k;
	    cum_steps = cum_steps + 1;
	    cum_step_units = cum_step_units + water_in_can;
	}

	if ( water_in_can == 0 )
	{
		save_current_plant = current_plant;
		save_cum_steps	= cum_steps + current_plant;
		save_cum_step_units = cum_step_units + UNITS_PER_CAN*(save_current_plant);
		trip = trip +1;
	}

	cout << "FAUCET " << '\t' ;
	cout << "	" << save_cum_steps << '\t' ;
	cout << "	" << water_in_can << '\t' ;
	cout << "	" << cum_step_units << endl;
	save_cum_steps	= save_cum_steps + save_current_plant;

	if ( k == 0 )
	{
		cout << endl <<"Plan Far: Total Steps = " << cum_steps << ", total step-units = " << cum_step_units  << endl;
		temp2 = cum_step_units;
	}
	return temp2;
}


int plan_far_rest_trips(int UNITS_PER_CAN, int &k, int plant_count,int &save_current_plant, int &save_cum_steps, int &save_cum_step_units,int &trip)
{
	int water_in_can;
	int temp2;
	for ( water_in_can = UNITS_PER_CAN ;  water_in_can > 0 && k > 0 ; water_in_can, k--)
	{
		cout << "Plant " << save_current_plant << '\t' ;
		cout << "	" << save_cum_steps << '\t' ;
		cout << "	" << water_in_can << '\t' ;
		cout << "	" << save_cum_step_units << endl;
		water_in_can--;

		if ( water_in_can == 0 )
			save_cum_steps = save_cum_steps + save_current_plant;
		else
			save_cum_steps = save_cum_steps + 1;

	    	save_current_plant = save_current_plant - 1;
	    	save_cum_step_units = save_cum_step_units + water_in_can;

	}

	cout << "FAUCET " << '\t' ;
	cout << "	" << save_cum_steps << '\t' ;
	cout << "	" << water_in_can << '\t' ;
	cout << "	" << save_cum_step_units << endl;

	if ( k == 0 )
	{
		cout << endl <<"Plan Far: Total Steps = " << save_cum_steps << ", total step-units = " << save_cum_step_units  << endl;
		temp2 = save_cum_step_units;
	}

	save_cum_steps = save_cum_steps + 1;
	save_cum_step_units = save_cum_step_units + 3;

	return temp2;
}

void plan_is_better(int temp1, int temp2, int plant_count)
{
	string var;
	int temp = 0;

	if ( temp1 < temp2 )
	{
		var = "Near";
		temp = temp2 - temp1 ;
	}
	else
	{
		var = "Far";
		temp = temp1 - temp2;
	}

	cout << endl;
	cout << "*** With " << plant_count << " plants, Plan " <<  var << " is better with " << temp << " fewer step-units. " << endl ;

}

