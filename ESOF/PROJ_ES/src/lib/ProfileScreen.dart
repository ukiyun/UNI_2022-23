import 'package:flutter/material.dart';
import 'package:firebase_auth/firebase_auth.dart';
import 'package:google_fonts/google_fonts.dart';
import 'LoginScreen.dart';
import 'package:cloud_firestore/cloud_firestore.dart';
import 'EventCard.dart';
import 'package:flutter/cupertino.dart';
import 'MainPage.dart';
import 'LoginScreen.dart';
import 'EditProfileScreen.dart';
import 'package:cityboard/AppBar.dart';


class ProfilePage extends StatefulWidget {
  const ProfilePage({Key? key}) : super(key: key);

  @override
  State<ProfilePage> createState() => _ProfilePageState();
}

class _ProfilePageState extends State<ProfilePage> {
  final FirebaseAuth _auth = FirebaseAuth.instance;
  var events = FirebaseFirestore.instance.collection('events');
  final TextEditingController _searchController = TextEditingController();
  final icon = CupertinoIcons.placemark_fill;
  Future<String> getCurrentEmail() async {
    final User? user = _auth.currentUser;
    final email = user!.email;
    return email!;
  }





  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: CustomAppBar(
        isLoggedIn: _auth.currentUser != null,
        onProfilePressed: () {
          Navigator.pushNamed(context, '/profile');
        },
        onLoginPressed: (){
          Navigator.pushReplacementNamed(context, '/');
        },
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
                              Container(
                                alignment: Alignment.topLeft,
                                child: const CircleAvatar(
                                  backgroundColor: Colors.white,
                                  radius: 50,
                                  child: CircleAvatar(
                                    backgroundColor: Colors.white,
                                    radius: 45,
                                    backgroundImage: AssetImage('assets/images/profilePic.png'),
                                  ),
                                ),
                              ),

                              const SizedBox(width: 30,),

                              // Name

                              Container(
                                alignment: Alignment.center,
                                child: Text(
                                  'John Smith',
                                  style: GoogleFonts.inter(
                                    fontSize: 30,
                                    fontWeight: FontWeight.bold,
                                    color: Colors.black,
                                  ),
                                ),
                              ),

                              // Edit Profile Button
                              Padding(
                                padding: const EdgeInsets.only(left: 20, top:3.5,),
                                child: ElevatedButton(
                                  onPressed: () {
                                    //Go To MainPage
                                    Navigator.push(
                                      context,
                                      MaterialPageRoute(builder: (context) => const EditProfilePage()),
                                    );
                                  },
                                  style: ElevatedButton.styleFrom(
                                    backgroundColor: Colors.white,
                                    shape: const CircleBorder(),
                                    padding: const EdgeInsets.all(8),
                                    shadowColor: Colors.black54,
                                  ), child: const Icon(
                                  Icons.border_color_rounded,
                                  color: Color(0xff885053),
                                  size:40,

                                ),
                                ),
                              ),

                            ],
                          ),

                          // User Email

                          Padding(
                            padding: const EdgeInsets.symmetric(horizontal: 8, vertical: 2),
                            child: Material(
                              elevation: 12,
                              shadowColor: const Color.fromRGBO(0, 0, 0, 1),
                              borderRadius: BorderRadius.circular(25),
                              child: TextFormField(
                                decoration: const InputDecoration(
                                  enabledBorder: OutlineInputBorder(
                                    borderRadius: BorderRadius.all(Radius.circular(25)),
                                    borderSide: BorderSide(color: Color(0xff885053), width: 2.0),

                                  ),
                                  labelText: 'Email',
                                  labelStyle:
                                    TextStyle(fontSize: 20, color: Colors.grey),
                                ),
                                ),
                            )
                            ),

                          const SizedBox(height: 10,),

                          // Going to events
                          Container(
                            padding: const EdgeInsets.only(left: 15, top: 5),
                            alignment: Alignment.centerLeft,
                            child: Text(
                              'Going to Events:',
                              style: GoogleFonts.inter(
                                fontSize: 25,
                                fontWeight: FontWeight.w700,
                                color: const Color(0xff885053),
                              ),
                            ),
                          ),

                          const SizedBox(height: 5,),

                          Container(
                              height: 100,
                              width: 380,
                              decoration: BoxDecoration(
                              color: Colors.white,
                              borderRadius: BorderRadius.circular(15),
                              border: Border.all(
                                color: const Color(0xff885053),
                                width: 2,
                                ),
                              ),
                            child: Column(
                            children: [
                              Row(
                              children: [
                                const SizedBox(width: 10, height: 30,),
                                Container(
                                  alignment: Alignment.centerLeft,
                                  child: const Padding(
                                    padding: EdgeInsets.only(top: 8),
                                    child: CircleAvatar(
                                      backgroundColor: Colors.white,
                                      radius: 40,
                                      child: CircleAvatar(
                                        backgroundColor: Colors.white,
                                        radius: 40,
                                        backgroundImage: AssetImage('assets/images/casaDamúsica.png'),
                                      ),
                                    ),
                                  ),
                                ),

                                const SizedBox(width: 10,),

                                Column(
                                  children: [
                                    Container(
                                      alignment: Alignment.topLeft,
                                      padding: const EdgeInsets.only(top: 1),
                                      child: Text(
                                        'Orquestra Casa da Música',
                                        style: GoogleFonts.inter(
                                          fontSize: 20,
                                          fontWeight: FontWeight.w700,
                                          color: Colors.black,
                                          textStyle: const TextStyle(
                                            decoration: TextDecoration.underline,
                                          ),
                                        ),
                                      ),
                                      ),
                                    const SizedBox(width: 10,),

                                    Container(
                                      alignment: Alignment.centerLeft,
                                      child: Row(
                                        children: [
                                          Padding(
                                            padding: const EdgeInsets.only(top: 10,),
                                            child: Text(
                                              '15 fev.   16h',
                                              style: GoogleFonts.inter(
                                                fontSize: 12,
                                                fontWeight: FontWeight.w700,
                                                color: Colors.black,
                                              ),
                                            ),
                                          ),
                                          const SizedBox(width: 50,),
                                          Padding(
                                              padding: const EdgeInsets.only(top: 10),
                                              child: Text(
                                                'Casa da Música',
                                                style: GoogleFonts.inter(
                                                  fontSize: 12,
                                                  fontWeight: FontWeight.w700,
                                                  color: Colors.black,
                                                ),
                                              ),
                                          ),
                                      ],
                                    ),
                                  ),
                                ]),
                                    ],
                                  ),
                                ]),
                              ),
                           const SizedBox(height: 5,),
                          Container(
                            height: 100,
                            width: 380,
                            decoration: BoxDecoration(
                              color: Colors.white,
                              borderRadius: BorderRadius.circular(15),
                              border: Border.all(
                                color: const Color(0xff885053),
                                width: 2,
                              ),
                            ),
                            child: Column(
                                children: [
                                  Row(
                                    children: [
                                      const SizedBox(width: 10, height: 30,),
                                      Container(
                                        alignment: Alignment.centerLeft,
                                        child: const Padding(
                                          padding: EdgeInsets.only(top: 8),
                                          child: CircleAvatar(
                                            backgroundColor: Colors.white,
                                            radius: 40,
                                            child: CircleAvatar(
                                              backgroundColor: Colors.white,
                                              radius: 40,
                                              backgroundImage: AssetImage('assets/images/casaDamúsica.png'),
                                            ),
                                          ),
                                        ),
                                      ),

                                      const SizedBox(width: 10,),

                                      Column(
                                          children: [
                                            Container(
                                              alignment: Alignment.topLeft,
                                              padding: const EdgeInsets.only(top: 1),
                                              child: Text(
                                                'Orquestra Casa da Música',
                                                style: GoogleFonts.inter(
                                                  fontSize: 20,
                                                  fontWeight: FontWeight.w700,
                                                  color: Colors.black,
                                                  textStyle: const TextStyle(
                                                    decoration: TextDecoration.underline,
                                                  ),
                                                ),
                                              ),
                                            ),
                                            const SizedBox(width: 10,),

                                            Container(
                                              alignment: Alignment.centerLeft,
                                              child: Row(
                                                children: [
                                                  Padding(
                                                    padding: const EdgeInsets.only(top: 10,),
                                                    child: Text(
                                                      '15 fev.   16h',
                                                      style: GoogleFonts.inter(
                                                        fontSize: 12,
                                                        fontWeight: FontWeight.w700,
                                                        color: Colors.black,
                                                      ),
                                                    ),
                                                  ),
                                                  const SizedBox(width: 50,),
                                                  Padding(
                                                    padding: const EdgeInsets.only(top: 10),
                                                    child: Text(
                                                      'Casa da Música',
                                                      style: GoogleFonts.inter(
                                                        fontSize: 12,
                                                        fontWeight: FontWeight.w700,
                                                        color: Colors.black,
                                                      ),
                                                    ),
                                                  ),
                                                ],
                                              ),
                                            ),
                                          ]),
                                    ],
                                  ),
                                ]),
                          ),
                          const SizedBox(height: 5,),

                          Container(
                            padding: const EdgeInsets.only(left: 15, top: 5),
                            alignment: Alignment.centerLeft,
                            /*
                            child: GestureDetector(
                              onTap: () {
                                Navigator.push(
                                  context,
                                  MaterialPageRoute(builder: (context) => EventCard(eventSnapshot: null,),
                                );
                              }, */
                            child: Text(
                              'View All',
                              style: GoogleFonts.inter(
                                fontSize: 14,
                                fontWeight: FontWeight.w700,
                                color: const Color(0xff885053),
                                textStyle: const TextStyle(
                                  decoration: TextDecoration.underline,
                                ),
                              ),
                            ),
                          ),
                          const SizedBox(height: 10,),

                          // Interested in events
                          Container(
                            padding: const EdgeInsets.only(left: 15, top: 5),
                            alignment: Alignment.centerLeft,
                            child: Text(
                              'Interested in Events:',
                              style: GoogleFonts.inter(
                                fontSize: 25,
                                fontWeight: FontWeight.w700,
                                color: const Color(0xff885053),
                              ),
                            ),
                          ),

                          const SizedBox(height: 5,),

                          Container(
                            height: 100,
                            width: 380,
                            decoration: BoxDecoration(
                              color: Colors.white,
                              borderRadius: BorderRadius.circular(15),
                              border: Border.all(
                                color: const Color(0xff885053),
                                width: 2,
                              ),
                            ),
                            child: Column(
                                children: [
                                  Row(
                                    children: [
                                      const SizedBox(width: 10, height: 30,),
                                      Container(
                                        alignment: Alignment.centerLeft,
                                        child: const Padding(
                                          padding: EdgeInsets.only(top: 8),
                                          child: CircleAvatar(
                                            backgroundColor: Colors.white,
                                            radius: 40,
                                            child: CircleAvatar(
                                              backgroundColor: Colors.white,
                                              radius: 40,
                                              backgroundImage: AssetImage('assets/images/casaDamúsica.png'),
                                            ),
                                          ),
                                        ),
                                      ),

                                      const SizedBox(width: 10,),

                                      Column(
                                          children: [
                                            Container(
                                              alignment: Alignment.topLeft,
                                              padding: const EdgeInsets.only(top: 1),
                                              child: Text(
                                                'Orquestra Casa da Música',
                                                style: GoogleFonts.inter(
                                                  fontSize: 20,
                                                  fontWeight: FontWeight.w700,
                                                  color: Colors.black,
                                                  textStyle: const TextStyle(
                                                    decoration: TextDecoration.underline,
                                                  ),
                                                ),
                                              ),
                                            ),
                                            const SizedBox(width: 10,),

                                            Container(
                                              alignment: Alignment.centerLeft,
                                              child: Row(
                                                children: [
                                                  Padding(
                                                    padding: const EdgeInsets.only(top: 10,),
                                                    child: Text(
                                                      '15 fev.   16h',
                                                      style: GoogleFonts.inter(
                                                        fontSize: 12,
                                                        fontWeight: FontWeight.w700,
                                                        color: Colors.black,
                                                      ),
                                                    ),
                                                  ),
                                                  const SizedBox(width: 50,),
                                                  Padding(
                                                    padding: const EdgeInsets.only(top: 10),
                                                    child: Text(
                                                      'Casa da Música',
                                                      style: GoogleFonts.inter(
                                                        fontSize: 12,
                                                        fontWeight: FontWeight.w700,
                                                        color: Colors.black,
                                                      ),
                                                    ),
                                                  ),
                                                ],
                                              ),
                                            ),
                                            const SizedBox(height: 5,),
                                          ]),
                                    ],
                                  ),
                                ]),
                          ),
                          const SizedBox(height: 5,),
                          Container(
                            height: 100,
                            width: 380,
                            decoration: BoxDecoration(
                              color: Colors.white,
                              borderRadius: BorderRadius.circular(15),
                              border: Border.all(
                                color: const Color(0xff885053),
                                width: 2,
                              ),
                            ),
                            child: Column(
                                children: [
                                  Row(
                                    children: [
                                      const SizedBox(width: 10, height: 30,),
                                      Container(
                                        alignment: Alignment.centerLeft,
                                        child: const Padding(
                                          padding: EdgeInsets.only(top: 8),
                                          child: CircleAvatar(
                                            backgroundColor: Colors.white,
                                            radius: 40,
                                            child: CircleAvatar(
                                              backgroundColor: Colors.white,
                                              radius: 40,
                                              backgroundImage: AssetImage('assets/images/casaDamúsica.png'),
                                            ),
                                          ),
                                        ),
                                      ),

                                      const SizedBox(width: 10,),

                                      Column(
                                          children: [
                                            Container(
                                              alignment: Alignment.topLeft,
                                              padding: const EdgeInsets.only(top: 1),
                                              child: Text(
                                                'Orquestra Casa da Música',
                                                style: GoogleFonts.inter(
                                                  fontSize: 20,
                                                  fontWeight: FontWeight.w700,
                                                  color: Colors.black,
                                                  textStyle: const TextStyle(
                                                    decoration: TextDecoration.underline,
                                                  ),
                                                ),
                                              ),
                                            ),
                                            const SizedBox(width: 10,),

                                            Container(
                                              alignment: Alignment.centerLeft,
                                              child: Row(
                                                children: [
                                                  Padding(
                                                    padding: const EdgeInsets.only(top: 10,),
                                                    child: Text(
                                                      '15 fev.   16h',
                                                      style: GoogleFonts.inter(
                                                        fontSize: 12,
                                                        fontWeight: FontWeight.w700,
                                                        color: Colors.black,
                                                      ),
                                                    ),
                                                  ),
                                                ],
                                              ),
                                            ),
                                          ]),

                                    ],
                                  ),
                                ]),
                          ),
                          const SizedBox(height: 5,),
                          Container(
                            padding: const EdgeInsets.only(left: 15, top: 5),
                            alignment: Alignment.centerLeft,
                            /*
                            child: GestureDetector(
                              onTap: () {
                                Navigator.push(
                                  context,
                                  MaterialPageRoute(builder: (context) => EventCard(eventSnapshot: null,),
                                );
                              }, */
                            child: Text(
                              'View All',
                              style: GoogleFonts.inter(
                                fontSize: 14,
                                fontWeight: FontWeight.w700,
                                color: const Color(0xff885053),
                                textStyle: const TextStyle(
                                  decoration: TextDecoration.underline,
                                ),
                              ),
                            ),
                          ),
                          ]),
                            ),
                            ),
                          ),
                          ),
                      ]),

        ),
                     ),
                );






            /*ElevatedButton(
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
                ), child: const Text(
                'Sign Out',
                style: TextStyle(
                  color: Colors.black,
                  fontSize: 20,
                ),
              ),
            )], */
  }
}