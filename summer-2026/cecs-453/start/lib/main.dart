import 'package:firebase_core/firebase_core.dart';
import 'package:flutter/material.dart';

import 'app.dart';
import 'firebase_options.dart';
import 'di/service_locator.dart';

// CECS 453
// Lab assignment 8
// Just Me: Carlos Aguilera
// Video link: https://www.loom.com/share/02f2e56f0cba459087c7a0872e4ea469

// TODO(codelab user): Get API key
const clientId = '';

void main() async {
  WidgetsFlutterBinding.ensureInitialized();
  await Firebase.initializeApp(options: DefaultFirebaseOptions.currentPlatform);
  setupLocator();
  runApp(const MyApp(clientId: clientId));
}
