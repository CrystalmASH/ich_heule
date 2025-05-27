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

Guard::Guard(){
    number = 0;
}

void Guard::leave(){

    chain = epilogues.dequeue();

    while(chain != nullptr){

        cpu.disable_int();
        if(guard.avail()){
            guard.enter();
            cpu.enable_int();

            gate = static_cast<Gate*>(chain);

            gate->epilogue();
            gate->queued(false);
            
            guard.retne();
        }

        cpu.enable_int();
        chain = epilogues.dequeue();
    }

    guard.retne();
}

void Guard::relay(Gate* item){
    cpu.disable_int();
    if(guard.avail()){
        guard.enter();
        cpu.enable_int();
        item->epilogue();
    }
    else {
        cpu.enable_int();
        if(!(item->queued())){

            item->queued(true);
            epilogues.enqueue(item);

        }
    }

}

Guard guard;

