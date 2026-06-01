import 'package:flutter/material.dart';
import 'package:coffee_card/coffee_prefs.dart';

class Home extends StatelessWidget {
  const Home({super.key});

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text(
          'Coffee Card',
          style: TextStyle(color: Colors.white, fontWeight: FontWeight.bold),
        ),
        backgroundColor: Colors.brown,
        centerTitle: true,
      ),
      body: Column(
        crossAxisAlignment: CrossAxisAlignment.stretch,
        children: [
          Container(
            color: Colors.brown[200],
            padding: const EdgeInsets.all(20),
            child: Text('How i like my coffee?'),
          ),
          Container(
            color: Colors.brown[100],
            padding: const EdgeInsets.all(20),
            child: CoffeePrefs(),
          ),
          Expanded(
            child: Image.asset(
              'assets/img/coffee_bg.jpg',
              fit: BoxFit.fitWidth,
              alignment: Alignment.bottomCenter,
            ),
          ),
        ],
      ),
    );
  }
}
