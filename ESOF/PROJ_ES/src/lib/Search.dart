


import 'package:cityboard/AppBar.dart';
import 'package:flutter/material.dart';
import 'package:firebase_auth/firebase_auth.dart';
import 'package:google_fonts/google_fonts.dart';

import 'package:cloud_firestore/cloud_firestore.dart';
import 'package:readmore/readmore.dart';

class Search extends StatefulWidget {


  const Search({Key? key}) : super(key: key);


  @override
  State<Search> createState() => _SearchState();
}

class _SearchState extends State<Search>{
  final FirebaseAuth _auth = FirebaseAuth.instance;
  final TextEditingController _searchController = TextEditingController();

  @override
  Widget build(BuildContext context){
    final String searchQuery = ModalRoute.of(context)!.settings.arguments.toString();
    print(searchQuery);



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
      body: getSearchResults(searchQuery),







    );


  }
  Future<List<QueryDocumentSnapshot<Map<String, dynamic>>> > getDocuments(String searchQuery) async{
    var events = await FirebaseFirestore.instance.collection('testEvents1').get();

    //Get the documents from the query snapshot that have the search query in their name
    var documents = events.docs.where((doc) => doc['eventName'].toString().toLowerCase().contains(searchQuery.toLowerCase())).toList();
    //print(documents);

    //Now you can use the documents in your widget tree
    return documents;

  }

  Widget getSearchResults(String searchQuery){

    buildTimeDate(timedate){
      var time = timedate.toDate();
      var dateString = time.toString().substring(0,10);
      var timeString = time.toString().substring(11,16);
      return dateString + ' ' + timeString;
    }
    Future<String> getTagName(tag) async {
      var string = tag.toString().substring(40, 60);
      var docRef = FirebaseFirestore.instance.doc(string);
      var docSnapshot = await docRef.get();
      return docSnapshot['tag'].toString();
    }

    Future<String> getTags(tags) async{
      List<String> tagList = [];
      for (var tag in tags){
        var tag1 = await getTagName(tag);
        tagList.add(tag1);

      }
      return tagList.join(', ');

    }


    return FutureBuilder<List<QueryDocumentSnapshot<Map<String, dynamic>>> >(
      future: getDocuments(searchQuery),
      builder: (context, snapshot){

        return ListView.builder(
          itemCount: snapshot.data?.length,
          itemBuilder: (context, index){
            return Padding(
              padding: const EdgeInsets.fromLTRB(10, 18, 10, 0),
              child: InkWell(
                onTap: (){
                  Navigator.pushNamed(context, '/eventCard', arguments: snapshot.data?[index]);
                },
                child: Container(
                  height: 150,
                  width: 400,
                  decoration: BoxDecoration(
                    borderRadius: BorderRadius.circular(15),
                    color: Colors.white,
                    border: Border.all(//#885053
                      color: const Color.fromRGBO(136, 80, 83, 1.0),
                      width: 1.5,
                    ),
                  ),
                  child:
                      Row(
                        crossAxisAlignment: CrossAxisAlignment.start,
                        children: [
                          Padding(
                            padding: const EdgeInsets.fromLTRB(10, 0, 0, 0),
                            child: ClipRRect(
                              borderRadius: BorderRadius.circular(35),

                              child: Image.network(snapshot.data?[index]['imageURL'],
                                height: 175,
                                width: 175,

                              ),
                            ),
                          ),
                          Padding(padding: const EdgeInsets.fromLTRB(10, 0, 0, 0),
                            child: Column(
                              crossAxisAlignment: CrossAxisAlignment.start,
                              children: [
                                Padding(
                                  padding: const EdgeInsets.fromLTRB(0, 12, 0, 0),
                                  child: SizedBox(
                                    width: 150,
                                    child: Text(snapshot.data?[index]['eventName'],
                                      style: TextStyle(
                                        color: Colors.black,
                                        fontSize: 20,
                                        fontWeight: FontWeight.w700,
                                        fontFamily: 'Inter',
                                        decoration: TextDecoration.underline,
                                        decorationColor:Colors.black,
                                        decorationThickness: 1.5,
                                      ),
                                      ),

                                    ),
                                  ),
                                Padding(
                                  padding: const EdgeInsets.fromLTRB(0, 0, 0, 0),
                                  child: SizedBox(
                                    width: 150,
                                    child: Text(buildTimeDate(snapshot.data?[index]['time&date']) ,
                                      style: TextStyle(
                                        color: Colors.black,
                                        fontSize: 15,
                                        fontWeight: FontWeight.w700,
                                        fontFamily: 'Inter',
                                      ),
                                    ),
                                  ),
                                ),
                                Padding(
                                  padding: const EdgeInsets.fromLTRB(0, 0, 0, 0),
                                  child: SizedBox(
                                    width: 150,
                                    child: Text(snapshot.data?[index]['venue'],
                                      style: TextStyle(
                                        color: Colors.black,
                                        fontSize: 15,
                                        fontWeight: FontWeight.w700,
                                        fontFamily: 'Inter',
                                      ),
                                    ),
                                  ),
                                ),

                                Padding(padding: const EdgeInsets.fromLTRB(0, 0, 0, 0),
                                  child: SizedBox(
                                    width: 150,
                                    child: FutureBuilder<String>(
                                      future: getTags(snapshot.data?[index]['tags']),
                                      builder: (context, snapshot1){
                                        if(snapshot1.hasData){
                                          return Text("Tags: " + snapshot1.data!,
                                            style: TextStyle(
                                              color: Colors.black,
                                              fontSize: 15,
                                              fontWeight: FontWeight.w700,
                                              fontFamily: 'Inter',
                                            ),
                                          );
                                        }
                                        else{
                                          return Text('Loading');
                                        }
                                      },
                                      ),
                                    ),
                                  ),






                              ],
                            ),

                          ),
                        ],
                      ),


                  ),
              ),

            );
          },);
      },
    );


  }





}











