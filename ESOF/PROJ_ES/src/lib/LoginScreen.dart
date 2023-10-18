import 'package:flutter/material.dart';
import 'package:firebase_auth/firebase_auth.dart';
import 'package:google_fonts/google_fonts.dart';
import 'RegisterScreen.dart';
import 'package:flutter/cupertino.dart';
import 'mainPage.dart';


import 'ForgotPassword1.dart';




class LoginPage extends StatefulWidget {
  const LoginPage({Key? key}) : super(key: key);

  @override
  State<LoginPage> createState() => _LoginPageState();
}

class _LoginPageState extends State<LoginPage> {
  final TextEditingController _usernameController = TextEditingController();
  final TextEditingController _passwordController = TextEditingController();


  @override
  Widget build(BuildContext context) {
    return Scaffold(
      resizeToAvoidBottomInset: false,
      backgroundColor: const Color.fromRGBO(82, 142, 163, 1.0),
      body: SafeArea(
        child: Center(
          child: Column(
            mainAxisAlignment: MainAxisAlignment.center,
            children: [
              // City Board Logo
              const Icon(
                CupertinoIcons.map_pin_ellipse,
                size: 100,
              ),

              const SizedBox(height: 50),
              Text(
                  'Cityboard',
                  style: GoogleFonts.bebasNeue(
                    fontSize: 52,
                    shadows: [
                      const Shadow(
                        blurRadius: 10,
                        color: Color.fromRGBO(0, 0, 0, .5),
                        offset: Offset(3, 3),
                      ),
                    ],
                  )
              ),
              const SizedBox(height: 10),

              const Text(
                'Your event tracking app!',
                style: TextStyle(
                  fontSize: 20,
                  fontWeight: FontWeight.w500,
                ),
              ),


              const SizedBox(height: 50, ),
              // Username/Email TextField
              Padding(
                padding: const EdgeInsets.symmetric(horizontal: 25.0),
                child: TextField(
                  controller: _usernameController,
                  decoration: InputDecoration(
                    filled: true,
                    fillColor: Colors.grey[200],
                    hintText: 'Username/Email',
                    enabledBorder: OutlineInputBorder(
                      borderRadius: BorderRadius.circular(12),
                      borderSide: BorderSide.none,
                    ),
                    focusedBorder: OutlineInputBorder(
                        borderRadius: BorderRadius.circular(12),
                        borderSide: const BorderSide(color: Color.fromRGBO(102, 75, 106, 1.0),
                        )
                    ),
                    contentPadding: const EdgeInsets.symmetric(
                      horizontal: 18,
                      vertical: 12,
                    ),
                  ),
                ),
              ),
              const SizedBox(height: 16),
              // Password TextField
              Padding(
                padding: const EdgeInsets.symmetric(horizontal: 25),
                child: TextField(
                  controller: _passwordController,
                  obscureText: true,
                  decoration: InputDecoration(
                    filled: true,
                    fillColor: Colors.grey[200],
                    hintText: 'Password',
                    enabledBorder: OutlineInputBorder(
                      borderRadius: BorderRadius.circular(12),
                      borderSide: BorderSide.none,
                    ),
                    focusedBorder: OutlineInputBorder(
                        borderRadius: BorderRadius.circular(12),
                        borderSide: const BorderSide(color: Color.fromRGBO(102, 75, 106, 1.0),
                        )
                    ),
                    contentPadding: const EdgeInsets.symmetric(
                      horizontal: 18,
                      vertical: 12,
                    ),
                  ),
                ),
              ),

              const SizedBox(height: 10),
              // Forgot Password Button
              Padding(
                padding: const EdgeInsets.symmetric(horizontal: 25) ,
                child: Row(
                  mainAxisAlignment: MainAxisAlignment.end,
                  children: [
                    GestureDetector(
                      onTap: () {
                        Navigator.push(
                          context,
                          MaterialPageRoute(builder: (context) => const ForgotPassword()),
                        );
                      },
                      child: const Text(
                        'Forgot Password?',
                        style: TextStyle(
                          fontWeight: FontWeight.w500,
                          fontSize: 12,
                        ),
                      ),
                    ),
                  ],
                ),
              ),

              const SizedBox(height: 20),

              // Login Button
              Padding(
                padding: const EdgeInsets.symmetric(horizontal: 25),
                child: SizedBox(
                  width: double.infinity,
                  height: 55,
                  child: ElevatedButton(
                    style: ElevatedButton.styleFrom(
                      backgroundColor: const Color.fromRGBO(102, 75, 106, 1.0),
                      shape: RoundedRectangleBorder(
                        borderRadius: BorderRadius.circular(12),
                      ),
                      padding: const EdgeInsets.symmetric(
                        horizontal: 18,
                        vertical: 12,
                      ),

                    ),

                    onPressed: () async{
                      try {
                        await FirebaseAuth.instance.signInWithEmailAndPassword(
                            email: _usernameController.text,
                            password: _passwordController.text
                        );
                        Navigator.pushReplacementNamed(context ,'/mainPage');

                      } on FirebaseAuthException catch (e) {
                        if (e.code == 'user-not-found') {

                          ScaffoldMessenger.of(context).showSnackBar(
                            SnackBar(
                              content: Container(
                                padding: const EdgeInsets.all(12),
                                height: 90,
                                decoration: const BoxDecoration(
                                  color: Color.fromRGBO(30, 176, 215, 2.0),
                                  borderRadius: BorderRadius.all(Radius.circular(20)),

                                ),
                                child:  Center(
                                  child: Column(
                                    children: const [
                                      Text('Oops!',
                                        style: TextStyle(
                                          color: Colors.white,
                                          fontSize: 20,
                                          fontWeight: FontWeight.bold,
                                          fontFamily: 'Inter',
                                          letterSpacing: 0,
                                        ),
                                      ),
                                      Text(
                                        'No user with that email.',
                                        style: TextStyle(
                                          color: Colors.white,
                                          fontSize: 20,
                                          fontWeight: FontWeight.bold,
                                          fontFamily: 'Inter',
                                          letterSpacing: 0,
                                        ),
                                      ),
                                    ],
                                  ),
                                ),
                              ),
                              behavior: SnackBarBehavior.floating,
                              backgroundColor: Colors.transparent,
                              elevation: 0,
                              duration: const Duration(milliseconds: 1000),

                            ),
                          );
                        } else if (e.code == 'wrong-password') {

                          ScaffoldMessenger.of(context).showSnackBar(
                            SnackBar(
                              content: Container(
                                padding: const EdgeInsets.all(16),
                                height: 90,
                                decoration: const BoxDecoration(
                                  color: Color.fromRGBO(30, 176, 215, 2.0),
                                  borderRadius: BorderRadius.all(Radius.circular(20)),

                                ),
                                child:  Center(
                                  child: Column(
                                    children: const [
                                      Text('Oops!',
                                        style: TextStyle(
                                          color: Colors.white,
                                          fontSize: 20,
                                          fontWeight: FontWeight.bold,
                                          fontFamily: 'Inter',
                                          letterSpacing: 0,
                                        ),
                                      ),
                                      Text(
                                        'Password Incorrect.',
                                        style: TextStyle(
                                          color: Colors.white,
                                          fontSize: 20,
                                          fontWeight: FontWeight.bold,
                                          fontFamily: 'Inter',
                                          letterSpacing: 0,
                                        ),
                                      ),
                                    ],
                                  ),
                                ),
                              ),
                              behavior: SnackBarBehavior.floating,
                              backgroundColor: Colors.transparent,
                              elevation: 0,
                              duration: const Duration(milliseconds: 1000),

                            ),
                          );
                        }
                      }

                    },

                    child: const Text('Sign In',
                      style: TextStyle(
                        color: Colors.white,
                        fontSize: 18,
                        fontWeight: FontWeight.bold,
                      ),),
                  ),
                ),
              ),

              const SizedBox(height: 25 ),

              // Sign Up Button

              Row(
                mainAxisAlignment: MainAxisAlignment.center,
                children: [
                  const Text(
                    'Don\'t have an account? ',
                    style: TextStyle(
                      fontWeight: FontWeight.bold,
                      fontSize: 17,
                    ),
                  ),
                  GestureDetector(
                    onTap: () {
                      Navigator.push(
                        context,
                        MaterialPageRoute(builder: (context) => const RegisterPage()),
                      );
                    },
                    child: const Text(
                      'Register Now',
                      style: TextStyle(
                        fontWeight: FontWeight.bold,
                        color: Colors.cyanAccent,
                        fontSize: 17,
                      ),
                    ),
                  ),
                ],
              ),
              // Enter as Guest
              const SizedBox(height: 35),
                      Padding(
                        padding: const EdgeInsets.symmetric(horizontal: 25),
                        child: SizedBox(
                          width: 200,
                          height: 50,
                          child: ElevatedButton(
                            style: ElevatedButton.styleFrom(
                              backgroundColor: const Color.fromRGBO(255, 255, 255, 0.4),
                              shape: RoundedRectangleBorder(
                              borderRadius: BorderRadius.circular(12),
                              ) ,
                              padding: const EdgeInsets.symmetric(
                                horizontal: 18,
                                vertical: 12,
                              ),
                            ),
                            onPressed: () async{
                              Navigator.pushReplacementNamed(context ,'/mainPage');
                            }, child: const Text('Enter as Guest',
                              style: TextStyle(
                                color: Colors.black,
                                fontSize: 16,
                                fontWeight: FontWeight.bold,
                              ),),
                            ),
                         ),
                        ),
            ],
          ),
        ),
      ),
    );
  }
}
