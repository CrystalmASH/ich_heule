/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                               L O C K E R                                 */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* The Locker class implements a lock that can be used to protect critical   */
/* sections. However, the variable only indicates whether the critical       */
/* section is free. Potentially necessary waiting, and protection for        */
/* counting functionality, must be implemented elsewhere.                    */
/*****************************************************************************/

#ifndef __Locker_include__
#define __Locker_include__

class Locker {
public:
	Locker(const Locker &copy) = delete; // prevent copying
	Locker& operator=(const Locker&) = delete; // prevent assignment
/* Add your code here */ 
	bool available;
	Locker(){available = true;}
	void enter(){available = false;}
	void retne(){available = true;}
	bool avail(){return available;}
};

#endif
