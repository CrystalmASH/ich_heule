/*****************************************************************************/
/* Operating-System Construction                                             */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                G U A R D                                  */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Using this class, we can synchronize activities with a critical section   */
/* with interrupt handlers that also access this critical section. This      */
/* synchronization takes place along the prologue/epilogue model.            */
/*****************************************************************************/

/* Add your code here */ 
#include "guard/guard.h"
#include "device/cgastr.h"
#include "guard/secure.h"

Guard::Guard(){
    number = 0;
}

void Guard::leave(){

    //kout<<"leave..."<<endl;
    //kout<<guard.avail()<<endl;
    //kout<<"leave..."<<endl;

    chain = epilogues.dequeue();

    while(chain != nullptr){
        

        //kout<<"while"<<endl;

        cpu.disable_int();

        //kout<<guard.avail()<<endl;

        if(guard.avail()){
            //guard.enter();

            //kout<<".....leave....."<<endl;

            Secure secure;

            cpu.enable_int();

            gate = static_cast<Gate*>(chain);

            gate->epilogue();
            gate->queued(false);
            
            //guard.retne();
        }

        cpu.enable_int();
        chain = epilogues.dequeue();
    }

    guard.retne();

    if(chain = nullptr) cpu_idle();
    //cpu.idle();
}

void Guard::relay(Gate* item){
    //kout<<"relay"<<endl;
    cpu.disable_int();
    //kout<<"realy0.5"<<endl;
    if(guard.avail()){
        //kout<<"relay1"<<endl;
        guard.enter();
        //Secure secure2;
        //number=1000;

        //Secure secure;

        //number=2000;

        cpu.enable_int();

        //kout<<".....relay1....."<<endl;

        item->epilogue();
        guard.retne();
        //kout<<"relay..."<<endl;
        //kout<<guard.avail()<<endl;
        //kout<<"relay..."<<endl;
        //guard.leave();
    }
    else {

        //kout<<item->queued()<<endl;
        //kout<<"relay2"<<endl;

        cpu.enable_int();
        if(!(item->queued())){


                //kout<<".....relay3....."<<endl;

                //guard.retne();
                
                cpu.disable_int();
                epilogues.enqueue(item);
                item->queued(true);
                cpu.enable_int();
            }
            
    }

    guard.leave();

    //cpu.idle();
    

}

Guard guard;

