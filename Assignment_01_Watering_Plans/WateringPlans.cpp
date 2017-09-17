#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
    const int UNITS_PER_CAN = 3; 								// water in can when it is filled
    const string INPUT_FILE_NAME = "counts.txt";
    int plant_count; 											// varibale to store input value from input file

    // temporary variables used to solve the problem

    int i = 0, j = 0, k = 0, l = 0;
    int cum_steps = 0, cum_step_units = 0;
    int cum_steps_far = 0, cum_step_units_far = 0;
    int current_plant = 0, current_plant_far = 0;
    int trip = 0;
    int save_current_plant =0, save_current_plant_far = 0;
    int save_cum_steps = 0, save_cum_steps_far = 0;
    int save_cum_step_units =0, save_cum_step_units_far = 0;
    int temp2 = 0, temp1 =0;

    ifstream input;

    // error opening file or if file is not present

    input.open(INPUT_FILE_NAME);
    if (input.fail())
    {
        cout << "Failed to open " << INPUT_FILE_NAME << endl;
        return -1;
    }

    // loop to run untill digit "0" is found in the input file. "0" indicates end of file

    do
    {
        input >> plant_count;

        if (plant_count == 0)
        {
        		break;
        }

        // Plan for Near Plant

        cout << endl;
        cout << "==========================" << endl;
        cout << " Plan Near with " << plant_count << " plants" << endl;
        cout << "==========================" << endl;
        cout << endl;
        cout << "Where      Cum. steps  Water amt.  Cum. step-units" << endl;
        cout << "---------  ----------  ----------  ---------------" << endl;



        	for ( i = 1 ; i <= plant_count ; i )
        	{
        		// First trip (when water in can is not over). Setting values in variables and printing
        		// Trip is one travel from faucet to the plant and back.

    			if ( trip == 0 )
    			{
    				for ( j = UNITS_PER_CAN ; j > 0 && i <= plant_count ; j -- , i ++)
    	   			{
    					current_plant = current_plant + 1;
    					cum_steps = cum_steps + 1;
    					cum_step_units = cum_step_units + j;

        			    	cout << "Plant " << current_plant << '\t' ;
        			    	cout << "	" << cum_steps << '\t' ;
        			    cout << "	" << j << '\t' ;
        			    cout << "	" << cum_step_units << endl;

        		    }

    				// saving variable values to pass to next trip for processing.

        			if ( j == 0)
    				{
        				save_current_plant = current_plant;
        				save_cum_steps	= cum_steps + 2*current_plant;
            	        save_cum_step_units = cum_step_units + UNITS_PER_CAN*save_current_plant;
            	        trip = trip +1;
        			}

        	        cum_steps = cum_steps + current_plant;
        	        cum_step_units = cum_step_units + j*current_plant;
        	        current_plant = 0;

       	        cout << "FAUCET " << '\t' ;
        	        cout << "	" << cum_steps << '\t' ;
    		        cout << "	" << j << '\t' ;
    		        cout << "	" << cum_step_units << endl;

    		        if ( i == plant_count + 1 )
    		        {
    		        		cout << endl << "Plan Near: Total Steps = " << cum_steps << ", total step-units = " << cum_step_units  << endl;
        		        	//	cout << "==========================" << endl;
    		        		temp1 = cum_step_units;
    		        }
        		}

        		else
        		{
        			// calculating variables and printing values for all other trips after the first one.

        			for ( j = UNITS_PER_CAN ;  j > 0 && i <= plant_count ; j -- , i ++)
        		    {
       				save_current_plant = save_current_plant + 1;
        				save_cum_steps = save_cum_steps + 1;
        				save_cum_step_units = save_cum_step_units + j;

        				cout << "Plant " << save_current_plant << '\t' ;
        				cout << "	" << save_cum_steps << '\t' ;
        				cout << "	" << j << '\t' ;
        				cout << "	" << save_cum_step_units << endl;
    			    }

        			save_cum_steps	= save_cum_steps + save_current_plant;
        	  	    save_cum_step_units = save_cum_step_units + j*save_current_plant;

    		        cout << "FAUCET " << '\t' ;
    		        cout << "	" << save_cum_steps << '\t' ;
    		        cout << "	" << j << '\t' ;
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

        		}
        	}



        	trip = 0;
        	cout << endl;

        	// Plan for Far Plant

        cout << "=========================" << endl;
        cout << " Plan Far with " << plant_count << " plants" << endl;
        cout << "=========================" << endl;
        cout << endl;
        cout << "Where      Cum. steps  Water amt.  Cum. step-units" << endl;
        cout << "---------  ----------  ----------  ---------------" << endl;



        for ( k = plant_count ; k > 0 ; k )
        	{
        		// Setting initial variable values

        		if ( trip == 0 )
        		{
        			cum_step_units_far = UNITS_PER_CAN*k;
        			cum_steps_far = k ;


        			for ( l = UNITS_PER_CAN ; l > 0 && k > 0 ; l )
        			{
        				cout << "Plant " << k << '\t' ;
        				cout << "	" << cum_steps_far << '\t' ;
        				cout << "	" << l << '\t' ;
        				cout << "	" << cum_step_units_far << endl;
        				k--;
        				l--;
        				current_plant_far = k;
        				cum_steps_far = cum_steps_far + 1;
        				cum_step_units_far = cum_step_units_far + l;



        			}

        			if ( l == 0 || k == 0)
               	{
        		 		save_current_plant_far = current_plant_far;
        		 		save_cum_steps_far	= cum_steps_far + current_plant_far;
                		save_cum_step_units_far = cum_step_units_far + UNITS_PER_CAN*(save_current_plant_far);
                		trip = trip +1;
                	}

        			cout << "FAUCET " << '\t' ;
        			cout << "	" << save_cum_steps_far << '\t' ;
        			cout << "	" << l << '\t' ;
        			cout << "	" << cum_step_units_far << endl;

        			save_cum_steps_far	= save_cum_steps_far + save_current_plant_far;


        			if ( k == 0 )
                	{
                		cout << endl <<"Plan Far: Total Steps = " << cum_steps_far << ", total step-units = " << cum_step_units_far  << endl;
                		//	cout << "==========================" << endl;
                		temp2 = cum_step_units_far;
                	}
        		}

    		else
    			{
    				// traversing the loop to calculate and print the values from after the 1st trip

    				for ( l = UNITS_PER_CAN ;  l > 0 && k > 0 ; l, k--)
    				{
    					cout << "Plant " << save_current_plant_far << '\t' ;
    					cout << "	" << save_cum_steps_far << '\t' ;
    					cout << "	" << l << '\t' ;
    					cout << "	" << save_cum_step_units_far << endl;
    					l--;


    					if ( l == 0 )
    						save_cum_steps_far = save_cum_steps_far + save_current_plant_far;
    					else
    						save_cum_steps_far = save_cum_steps_far + 1;

    					save_current_plant_far = save_current_plant_far - 1;
                		save_cum_step_units_far = save_cum_step_units_far + l;

                	}


               	cout << "FAUCET " << '\t' ;
               	cout << "	" << save_cum_steps_far << '\t' ;
               	cout << "	" << l << '\t' ;
               	cout << "	" << save_cum_step_units_far << endl;




               	if ( k == 0 )
               	{
               		cout << endl <<"Plan Far: Total Steps = " << save_cum_steps_far << ", total step-units = " << save_cum_step_units_far  << endl;
               		//cout << "==========================" << endl;
               		temp2 = save_cum_step_units_far;
               	}

               	save_cum_steps_far = save_cum_steps_far + 1;
               	save_cum_step_units_far = save_cum_step_units_far + 3;


               	save_cum_steps	= save_cum_steps + save_current_plant;
               	save_cum_step_units = save_cum_step_units + UNITS_PER_CAN*save_current_plant;
                trip = trip +1;

    			}

        	}


        // Which plan is better? Better means fewer step-units.
        // determining better plan

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




        // resetting values for next plant_count iteration (if available)

        cum_steps = 0, cum_step_units = 0;
        cum_steps_far = 0, cum_step_units_far = 0;
        current_plant = 0;
        current_plant_far = 0;
        save_current_plant =0;
        save_current_plant_far = 0;
        save_cum_steps = 0, save_cum_steps_far = 0;
        save_cum_step_units =0, save_cum_step_units_far = 0;
        i = 0, j = 0, k = 0, l = 0;
        temp1 = 0, temp2 = 0;
        trip = 0;

    } while (plant_count > 0);

    return 0;
}
