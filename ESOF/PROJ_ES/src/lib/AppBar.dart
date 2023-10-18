import 'package:flutter/material.dart';
import 'package:firebase_auth/firebase_auth.dart';
import 'LoginScreen.dart';

class CustomAppBar extends StatelessWidget implements PreferredSizeWidget {
  final bool isLoggedIn;
  final VoidCallback onProfilePressed;
  final VoidCallback onLoginPressed;
  final TextEditingController _searchController = TextEditingController();

   CustomAppBar({
    Key? key,
    required this.isLoggedIn,
    required this.onProfilePressed,
    required this.onLoginPressed,
  }) : super(key: key);

  @override
  Size get preferredSize => const Size.fromHeight(kToolbarHeight);

  @override
  Widget build(BuildContext context) {
    return AppBar(
      backgroundColor: const Color(0xFF885053),
      automaticallyImplyLeading: false,
      title: SizedBox(
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
              contentPadding: const EdgeInsets.symmetric(
                horizontal: 18,
                vertical: 10,
              ),
              border: OutlineInputBorder(
                borderRadius: BorderRadius.circular(15),
                borderSide: BorderSide.none,
              ),
              suffixIcon: IconButton(
                onPressed: () {
                  Navigator.pushNamed(context, '/search', arguments: _searchController.text);
                },
                icon: const Icon(
                  Icons.search_rounded,
                  color: Color(0xFF885053),
                ),
              ),
            ),
          ),
        ),
      ),
      actions: [
        if (isLoggedIn)
          Padding(
            padding: const EdgeInsets.only(right: 8.0, top: 5.0),
            child: GestureDetector(
              onTap: onProfilePressed,
              child: Image.asset(
                'assets/images/profilePic.png',
                height: 60,
                width: 60,
              ),
            ),
          )
        else
          Padding(
            padding: const EdgeInsets.fromLTRB(0, 10, 10, 10),
            child: ElevatedButton(
              style: ElevatedButton.styleFrom(
                backgroundColor: Colors.white,
                shape: RoundedRectangleBorder(
                  borderRadius: BorderRadius.circular(15),
                ),
                padding: const EdgeInsets.symmetric(
                  horizontal: 0,
                  vertical: 0,
                ),
              ),
              onPressed: onLoginPressed,
              child: const Text(
                'Login',
                style: TextStyle(
                  color: Colors.black,
                  fontSize: 10,
                  fontWeight: FontWeight.w700,
                  fontFamily: 'Inter',
                ),
              ),
            ),
          ),
      ],
    );
  }
}
