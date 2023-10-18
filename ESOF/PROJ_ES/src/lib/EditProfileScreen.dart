import 'package:cityboard/ProfileScreen.dart';
import 'package:flutter/material.dart';
import 'package:firebase_auth/firebase_auth.dart';
import 'package:google_fonts/google_fonts.dart';
import 'LoginScreen.dart';
import 'package:cloud_firestore/cloud_firestore.dart';
import 'EventCard.dart';
import 'package:flutter/cupertino.dart';
import 'MainPage.dart';
import 'LoginScreen.dart';
import 'RegisterScreen.dart';


class EditProfilePage extends StatefulWidget {
  const EditProfilePage({Key? key}) : super(key: key);

  @override
  State<EditProfilePage> createState() => _EditProfilePageState();
}

class _EditProfilePageState extends State<EditProfilePage> {
  final FirebaseAuth _auth = FirebaseAuth.instance;
  var events = FirebaseFirestore.instance.collection('events');
  final TextEditingController _searchController = TextEditingController();
  final icon = CupertinoIcons.placemark_fill;





  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        backgroundColor: const Color(0xff885053),
        automaticallyImplyLeading: false,
        title:  SizedBox(
          height: 37,
          width: 300,
          child: Material(
            elevation: 5,
            borderRadius: BorderRadius.circular(15),
            shadowColor: const Color.fromRGBO(0, 0, 0, 0.25),
            child: TextField(
              controller: _searchController,
              decoration: InputDecoration(
                filled: true,
                fillColor: Colors.white,
                hintText: 'Search',
                contentPadding: const EdgeInsets.fromLTRB(10, 0, 0, 0),
                border: const OutlineInputBorder(
                  borderRadius: BorderRadius.all(Radius.circular(15)),
                  borderSide: BorderSide.none,

                ),
                suffixIcon: IconButton(
                  onPressed: () {

                  },
                  icon: const Icon(Icons.search_rounded,
                    color: Color(0xff885053),),
                ),

              ),

            ),

          ),

        ),

        actions: [
          // back to map button
          Padding(
            padding: const EdgeInsets.only(top: 5, bottom: 5,),
            child: ElevatedButton(
              onPressed: () {
                //Go To MainPage
                Navigator.push(
                  context,
                  MaterialPageRoute(builder: (context) => const MainPage()),
                );
              },
              style: ElevatedButton.styleFrom(
                backgroundColor: const Color.fromRGBO(255, 255, 255, 0.74),
                shape: const CircleBorder(),
                padding: const EdgeInsets.all(0),
                shadowColor: Colors.black54,
              ), child: const Icon(
              CupertinoIcons.placemark_fill,
              color: Color(0xff885053),
              size:40,
            ),
            ),
          ),
        ],

      ),

      backgroundColor: const Color.fromRGBO(82, 142, 163, 2.0),


      body: Center(
        child: SingleChildScrollView(
          reverse: true,
          child: Column(
              mainAxisAlignment: MainAxisAlignment.center,
              children: [
                Padding(
                  padding: const EdgeInsets.all(8),

                  child: SingleChildScrollView(
                    child: Container(
                      height: 750,
                      width: 400,
                      decoration: BoxDecoration(
                        color: Colors.white,
                        borderRadius: BorderRadius.circular(20),
                        boxShadow: const [
                          BoxShadow(
                            color: Colors.black54,
                            blurRadius: 30,
                            offset: Offset(2.0, 2.0),
                          ),
                        ],
                      ),
                      child: SingleChildScrollView(
                        child: Column(
                            children:  [
                              const SizedBox(height: 8,),
                              // Profile Picture
                              Row(
                                children: [
                                  Stack(
                                    children: <Widget>[
                                    Container(
                                      padding: const EdgeInsets.only(top: 10, left: 100),
                                      alignment: Alignment.center,
                                      child: const CircleAvatar(
                                        backgroundColor: Colors.white,
                                        radius: 90,
                                        child: CircleAvatar(
                                          backgroundColor: Colors.white,
                                          radius: 85,
                                          backgroundImage: AssetImage('assets/images/profilePic.png'),

                                        ),
                                      ),
                                    ),
                                      Align(

                                        child: Container(
                                          alignment: Alignment.center,
                                          padding: const EdgeInsets.only(top: 120, left: 210),
                                          child: CircleAvatar(
                                            backgroundColor: const Color(0xff885053),
                                            radius: 25,
                                            child: IconButton(
                                              onPressed: () {
                                                //Go To MainPage
                                                Navigator.push(
                                                  context,
                                                  MaterialPageRoute(builder: (context) => const MainPage()),
                                                );
                                              },
                                              icon: const Padding(
                                                padding: EdgeInsets.only(left: 1),
                                                child: Icon(Icons.edit,
                                                  color: Colors.white,
                                                  size: 30,
                                                ),
                                              ),
                                            ),
                                          ),
                                        ),
                                      )
                                  ]),

                                  const SizedBox(width: 30,),



                                ],
                              ),

                              // Change First Name
                              const SizedBox(height: 40,),

                              Container(
                                padding: const EdgeInsets.only(left: 15, top: 5),
                                alignment: Alignment.centerLeft,
                                child: Text(
                                  'First Name',
                                  style: GoogleFonts.inter(
                                    fontSize: 16,
                                    fontWeight: FontWeight.w700,
                                    color: const Color(0xff885053),
                                  ),
                                ),
                              ),

                              Padding(
                                padding: const EdgeInsets.symmetric(horizontal: 8, vertical: 5),
                                child: TextField(
                                  //controller: _firstNameController,
                                  decoration: InputDecoration(
                                    filled: true,
                                    fillColor: Colors.grey[200],
                                    hintText: 'John',
                                    enabledBorder: OutlineInputBorder(
                                      borderRadius: BorderRadius.circular(20),
                                      borderSide: const BorderSide(
                                        color: Color(0xff885053),
                                      ),
                                    ),
                                    contentPadding: const EdgeInsets.symmetric(
                                      horizontal: 18,
                                      vertical: 12,
                                    ),
                                  ),
                                ),
                              ),

                              const SizedBox(height: 10,),

                              // Change Last Name

                              Container(
                                padding: const EdgeInsets.only(left: 15, top: 5),
                                alignment: Alignment.centerLeft,
                                child: Text(
                                  'Last Name',
                                  style: GoogleFonts.inter(
                                    fontSize: 16,
                                    fontWeight: FontWeight.w700,
                                    color: const Color(0xff885053),
                                  ),
                                ),
                              ),

                              Padding(
                                padding: const EdgeInsets.symmetric(horizontal: 8, vertical: 5),
                                child: TextField(
                                  //controller: _firstNameController,
                                  decoration: InputDecoration(
                                    filled: true,
                                    fillColor: Colors.grey[200],
                                    hintText: 'Smith',
                                    enabledBorder: OutlineInputBorder(
                                      borderRadius: BorderRadius.circular(20),
                                      borderSide: const BorderSide(
                                        color: Color(0xff885053),
                                      ),
                                    ),
                                    contentPadding: const EdgeInsets.symmetric(
                                      horizontal: 18,
                                      vertical: 12,
                                    ),
                                  ),
                                ),
                              ),

                              const SizedBox(height: 10,),

                              // Change Email

                              Container(
                                padding: const EdgeInsets.only(left: 15, top: 5),
                                alignment: Alignment.centerLeft,
                                child: Text(
                                  'Email',
                                  style: GoogleFonts.inter(
                                    fontSize: 16,
                                    fontWeight: FontWeight.w700,
                                    color: const Color(0xff885053),
                                  ),
                                ),
                              ),

                              Padding(
                                padding: const EdgeInsets.symmetric(horizontal: 8, vertical: 5),
                                child: TextField(
                                  //controller: _firstNameController,
                                  decoration: InputDecoration(
                                    filled: true,
                                    fillColor: Colors.grey[200],
                                    hintText: 'johnsmith@gmail.com',
                                    enabledBorder: OutlineInputBorder(
                                      borderRadius: BorderRadius.circular(20),
                                      borderSide: const BorderSide(
                                        color: Color(0xff885053),
                                      ),
                                    ),
                                    contentPadding: const EdgeInsets.symmetric(
                                      horizontal: 18,
                                      vertical: 12,
                                    ),
                                  ),
                                ),
                              ),

                              const SizedBox(height: 10,),

                              // Change Password

                              Container(
                                padding: const EdgeInsets.only(left: 15, top: 5),
                                alignment: Alignment.centerLeft,
                                child: Text(
                                  'Password',
                                  style: GoogleFonts.inter(
                                    fontSize: 16,
                                    fontWeight: FontWeight.w700,
                                    color: const Color(0xff885053),
                                  ),
                                ),
                              ),

                              Padding(
                                padding: const EdgeInsets.symmetric(horizontal: 8, vertical: 5),
                                child: TextField(
                                  //controller: _firstNameController,
                                  obscureText: true,
                                  decoration: InputDecoration(
                                    filled: true,
                                    fillColor: Colors.grey[200],
                                    hintText: 'password',

                                    enabledBorder: OutlineInputBorder(
                                      borderRadius: BorderRadius.circular(20),
                                      borderSide: const BorderSide(
                                        color: Color(0xff885053),
                                      ),
                                    ),
                                    contentPadding: const EdgeInsets.symmetric(
                                      horizontal: 18,
                                      vertical: 12,
                                    ),
                                  ),
                                ),
                              ),


                              const SizedBox(height: 30,),

                              // Save Button

                              ElevatedButton(
                                onPressed: () {
                                  //Go Back to Profile Page
                                  Navigator.push(
                                    context,
                                    MaterialPageRoute(builder: (context) => const ProfilePage()),
                                  );
                                },
                                style: ElevatedButton.styleFrom(
                                  backgroundColor: const Color(0xff885053),
                                  shape: const RoundedRectangleBorder(
                                    borderRadius: BorderRadius.all(Radius.circular(10)),
                                  ),
                                  padding: const EdgeInsets.symmetric(
                                    horizontal: 160,
                                    vertical: 15,
                                  ),
                              ),child: const Text(
                                'Save',
                                style: TextStyle(
                                  color: Colors.white,
                                  fontSize: 20,
                                ),
                              ),
                              ),

                              const SizedBox(height: 10,),

                              ElevatedButton(
                                onPressed: () async {
                                /*  var eventsDoc = await events.get();
                                  var event = eventsDoc.docs[0];*/
                                  _auth.signOut();
                                  Navigator.push(context,MaterialPageRoute(builder: (context) => LoginPage()));
                                },
                                  style: ElevatedButton.styleFrom(
                                    backgroundColor: Colors.white,
                                    shape: const RoundedRectangleBorder(
                                      borderRadius: BorderRadius.all(Radius.circular(10)),
                                    ),
                                    padding: const EdgeInsets.symmetric(
                                      horizontal: 140,
                                      vertical: 15,
                                    ),
                                  ), child: const Text(
                                  'Sign Out',
                                  style: TextStyle(
                                    color: Colors.black,
                                    fontSize: 20,
                                  ),
                                ),
                              )],
                        ),
                      ),
                        ),
                ),
              ),
        ]),
      ),
    ),
    );
  }
}