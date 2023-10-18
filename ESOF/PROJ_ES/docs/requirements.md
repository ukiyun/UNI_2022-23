
## Requirements

### Use case model 

 <p align="center" justify="center">
  <img src="https://github.com/FEUP-LEIC-ES-2022-23/2LEIC03T2/blob/main/images/Use Case Diagram.drawio.png"/>
</p>

Briefly describe each use case mentioning the following:

* **Actor**. Name only the actor that will be initiating this use case, i.e. a person or other entity external to the software system being specified who interacts with the system and performs use cases to accomplish tasks. 
* **Description**. Provide a brief description of the reason for and outcome of this use case, or a high-level description of the sequence of actions and the outcome of executing the use case. 
* **Preconditions and Postconditions**. Include any activities that must take place, or any conditions that must be true, before the use case can be started (preconditions). Describe also the state of the system at the conclusion of the use case execution (postconditions). 

* **Normal Flow**. Provide a detailed description of the user actions and system responses that will take place during execution of the use case under normal, expected conditions. This dialog sequence will ultimately lead to accomplishing the goal stated in the use case name and description. This is best done as a numbered list of actions performed by the actor, alternating with responses provided by the system. 
* **Alternative Flows and Exceptions**. Document other, legitimate usage scenarios that can take place within this use case, stating any differences in the sequence of steps that take place. In addition, describe any anticipated error conditions that could occur during execution of the use case, and define how the system is to respond to those conditions. 

|||
| --- | --- |
| *Name* | Mark Event as 'Going to' |
| *Actor* |  User | 
| *Description* | The User sets their status towards an Event as 'Going to'. |
| *Preconditions* | - Event is available. |
| *Postconditions* | - The User's information is updated, with the new status towards the Event being 'Goint to'. |
| *Normal flow* | 1. The User accesses the app by logging into their account.<br> 2. The User accesses the event page through the app.<br> 3. The User selects the 'Going to' option.<br> 4. The system updates the user's information in the external database. |
| *Alternative flows and exceptions* | 1. [Failed Connection to Server] If, during the procedute, the User's device loses connection to the Internet, and thus, its ability to comunicate with the server, the procedure fails. |

|||
| --- | --- |
| *Name* | Mark Event as 'Interested' |
| *Actor* |  User | 
| *Description* | The User sets their status towards an Event as 'Interested'. |
| *Preconditions* | - The event is available. |
| *Postconditions* | - The User's information is updated, with the new status towards the Event being 'Interested'. |
| *Normal flow* | 1. The User accesses the app by logging into their account.<br> 2. The User accesses the event page through the app.<br> 3. The User selects the 'Interested' option.<br> 4. The system updates the user's information in the external database. |
| *Alternative flows and exceptions* | 1. [Failed Connection to Server] If, during the procedute, the User's device loses connection to the Internet, and thus, its ability to comunicate with the server, the procedure fails. |

|||
| --- | --- |
| *Name* | Unmark Event |
| *Actor* |  User | 
| *Description* | The User removes their status towards an event. |
| *Preconditions* | - The event is available. <br> - The User's status towards the event is either 'Going to' or 'Interested'. |
| *Postconditions* | - The User's status towards the event is removed. |
| *Normal flow* | 1. The User accesses the app by logging into their account.<br> 2. The User accesses the event page through the app.<br> 3. The User selects the current option with their status towards the event.<br> 4. The User comfirms. <br>5. The system updates the user's information in the external database. |
| *Alternative flows and exceptions* | 1. [Failed Connection to Server] If, during the procedute, the User's device loses connection to the Internet, and thus, its ability to comunicate with the server, the procedure fails. |

|||
| --- | --- |
| *Name* | Check Event Information |
| *Actor* |  User | 
| *Description* | The User accesses the event's page to find out information regarding it. |
| *Preconditions* | - The event is available. |
| *Postconditions* | - The User learns the information it desires from the event. |
| *Normal flow* | 1. The User accesses the app by logging into their account.<br> 2. The User accesses the event page through the app.<br> 3. The User reads the information present in the event page. |
| *Alternative flows and exceptions* | 1. [Failed Connection to Server] If, during the procedute, the User's device loses connection to the Internet, and thus, its ability to comunicate with the server, the procedure fails. |

|||
| --- | --- |
| *Name* | Search for Events |
| *Actor* |  User | 
| *Description* | The User searches for events, whether to discover new events, or to access one they already know of. |
| *Preconditions* | - The event is available. |
| *Postconditions* | - The app provides the possible results for the terms the User searched for. |
| *Normal flow* | 1. The User accesses the app by logging into their account.<br> 2. The user types out a search term on the search bar.<br> 2. The app provides the User with option that fulfill their search requirements.<br> 3. The User selects the option they were looking for. |
| *Alternative flows and exceptions* | 1. [Failed Connection to Server] If, during the procedute, the User's device loses connection to the Internet, and thus, its ability to comunicate with the server, the procedure fails.<br> 2. [Search does not provide any proper results] If, as a result of the search in step 2, no results that fulfill the User's requirements are provided, the User must return to step 2, or simply give up. |

### Domain model

 <p align="center" justify="center">
  <img src="https://github.com/FEUP-LEIC-ES-2022-23/2LEIC03T2/blob/main/images/DomainModel_t2_v1.png"/>
</p>
