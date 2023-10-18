


import 'package:flutter/material.dart';
import 'package:firebase_auth/firebase_auth.dart';
import 'package:google_fonts/google_fonts.dart';
import 'package:cityboard/AppBar.dart';
import 'package:cloud_firestore/cloud_firestore.dart';
import 'package:readmore/readmore.dart';

class EventCard extends StatefulWidget {


  const EventCard({Key? key,}) : super(key: key);


  @override
  State<EventCard> createState() => _EventCardState();
}

class _EventCardState extends State<EventCard>{
  final FirebaseAuth _auth = FirebaseAuth.instance;
  final TextEditingController _searchController = TextEditingController();
  bool isReadMore = false;

  @override
  Widget build(BuildContext context){
    final eventSnapshot = ModalRoute.of(context)!.settings.arguments as QueryDocumentSnapshot<Map<String, dynamic>>;
    var time = eventSnapshot['time&date'].toDate();
    var dateString = time.toString().substring(0,10);
    var timeString = time.toString().substring(11,16);
    var description = eventSnapshot['description'];
    var eventName = eventSnapshot['eventName'];
    var tags = eventSnapshot['tags'];
    var entryRequirements = eventSnapshot['entryRequirements'];
    var venue = eventSnapshot['venue'];



    print(tags);

    return Scaffold(
        backgroundColor: const Color.fromRGBO(82, 142, 163, 2.0),
      appBar: CustomAppBar(
      isLoggedIn: _auth.currentUser != null,
      onProfilePressed: () {
        Navigator.pushNamed(context, '/profile');
      },
      onLoginPressed: (){
        Navigator.pushReplacementNamed(context, '/');
      },
      ),



      body:


        SingleChildScrollView(
          child: Column(
            mainAxisAlignment: MainAxisAlignment.center,
            children:<Widget>[


              Center(
                child: Container(
                  height: (MediaQuery.of(context).size.height),
                  width: (MediaQuery.of(context).size.width) - 20 ,

                  decoration: BoxDecoration(
                    borderRadius: BorderRadius.circular(15),
                    color: Colors.white,

                  ),
                  child: Column(
                    children: [


                      Padding(
                          padding: const EdgeInsets.fromLTRB(0, 0, 0, 0),
                          child: ClipRRect(
                            borderRadius: BorderRadius.circular(20),
                            child: Image.network(eventSnapshot['imageURL'],
                              height: 264,
                              width: 383,

                            ),
                          ),
                        ),


                      Padding(
                        padding: const EdgeInsets.fromLTRB(3, 0, 190, 0),
                        child:  Text(eventName,
                          style: GoogleFonts.inter( textStyle: TextStyle(
                            fontSize: 29,
                            fontWeight: FontWeight.w600,
                            fontFamily: 'Inter',

                          ),
                          ),
                        ),
                      ),
                      Row(

                        //Retrieve a timestamp from the database and convert it to a DateTime object
                      children: [

                          Padding(

                            padding: const EdgeInsets.fromLTRB(7, 0, 0, 0),

                            child: Text(dateString + ' ' + timeString,
                              style: TextStyle(
                                fontSize: 18,
                                fontWeight: FontWeight.w500,
                                fontFamily: 'Inter',
                              ),
                            ),
                          ),

                          Padding(padding: const EdgeInsets.fromLTRB(7, 0, 0, 0),

                            child: Text(venue,
                              style: TextStyle(
                                fontSize: 18,
                                fontWeight: FontWeight.w500,
                                fontFamily: 'Inter',
                              ),
                            ),
                          ),
                        ],
                      ),

                      FutureBuilder<Widget>(
                      future: buildPlusTags(tags),
                      builder: (BuildContext context, AsyncSnapshot<Widget> snapshot) {
                        if (snapshot.connectionState == ConnectionState.waiting) {
                          return CircularProgressIndicator(); // Display a loading indicator while waiting
                        } else if (snapshot.hasError) {
                          return Text('Error: ${snapshot.error}');
                        } else {
                          return snapshot.data!;
                        }
                      },
                    ),

                      Column(
                        children: [
                          Padding(padding: const EdgeInsets.fromLTRB(7, 0, 0, 0),

                          child: buildText(description)

                          ),
                          
                          Padding(padding: const EdgeInsets.fromLTRB(7, 5, 0, 0),

                              child: Column(
                                children: [
                                  Row(
                                    children: [
                                      Text('Entry Requirements',
                                        style: TextStyle(
                                          fontSize: 18,
                                          fontWeight: FontWeight.w500,
                                          fontFamily: 'Inter',
                                        ),
                                      ),
                                    ],
                                  ),
                                  Row(
                                    children: [
                                      Padding(padding: const EdgeInsets.fromLTRB(0, 5, 0, 0),

                                        child: Text(entryRequirements,
                                          style: TextStyle(
                                            fontSize: 15,
                                            fontWeight: FontWeight.w400,
                                            fontFamily: 'Inter',
                                          ),
                                        ),


                                      )

                                    ],
                                  ),
                                ],
                              )
                          ),




                        ],
                      ),










                    ]
                  )
    )
    )
    ]
          ),//children

          ),


    );
  }



    Future<Widget> buildPlusTags(tags)  async {


      var list = <Widget>[];


      for(var tag in tags){

        var tag1 =  await getTagName(tag);

          Widget tagWidget =  buildTag(tag1);

          list.add(tagWidget);


        };



      print(list);
      return  Row(children: list);
    }



  Future<String> getTagName(tag) async {
    var string = tag.toString().substring(40, 60);
    var docRef = FirebaseFirestore.instance.doc(string);
    var docSnapshot = await docRef.get();
    return docSnapshot['tag'].toString();
  }





  Widget buildText(String text){

    return ReadMoreText(
      text,
      trimLines: 3,
      trimMode: TrimMode.Line,
      trimCollapsedText: 'Read More',
      trimExpandedText: 'Read Less',
      colorClickableText: Color.fromRGBO(136, 80, 83, 1.0),

      style: TextStyle(

          fontSize: 17,
          fontWeight: FontWeight.w500,
          fontFamily: 'Inter',

      ),
    );
  }

  Widget buildTag(String text) {
    return Padding(padding: const EdgeInsets.fromLTRB(6, 10, 0, 10),
      child: Container(
        height: 28,
        width: 105,
        decoration:
        BoxDecoration(
          borderRadius: BorderRadius.circular(29),
          color: Color.fromRGBO(136, 80, 83, 0.6),


        ),
        child: Center(
          child: Text(text,
            style: TextStyle(
                fontSize: 17,
                fontWeight: FontWeight.w500,
                color: Colors.white,
                fontFamily:  'Inter'
            ),
          ),
        ),
      ),


    );


  }
}


