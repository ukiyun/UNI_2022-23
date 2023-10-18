import 'package:firebase_core/firebase_core.dart';
import 'package:flutter/material.dart';
import 'LoginScreen.dart';
import 'RegisterScreen.dart';
import 'MainPage.dart';
import 'ProfileScreen.dart';
import 'EventCard.dart';
import 'Search.dart';

void main() async {
  WidgetsFlutterBinding.ensureInitialized();
  await Firebase.initializeApp();

  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({Key? key}): super(key: key);

  // This widget is the root of your application.
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'CityBoard',
      debugShowCheckedModeBanner: false,
      initialRoute: '/',
      routes: {
        '/': (context) => LoginPage(),
        '/register': (context) => RegisterPage(),
        '/mainPage': (context) => const MainPage(),
        '/profile': (context) => const ProfilePage(),
        '/search': (context) => const Search(),
        '/eventCard': (context) =>  EventCard(),

      },

    );
  }
}
