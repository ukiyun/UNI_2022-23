import 'package:cloud_firestore/cloud_firestore.dart';
import 'package:flutter/material.dart';
import 'package:firebase_auth/firebase_auth.dart';
import 'LoginScreen.dart';
import 'package:cityboard/AppBar.dart';

class MainPage extends StatefulWidget {
  const MainPage({Key? key}) : super(key: key);

  @override
  State<MainPage> createState() => _MainPageState();
}

class _MainPageState extends State<MainPage> {
  final FirebaseAuth _auth = FirebaseAuth.instance;
  final TextEditingController _searchController = TextEditingController();
  var events = FirebaseFirestore.instance.collection('testEvents1').get();




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



    );









  }
}


