import 'package:flutter/material.dart';
import 'package:provider/provider.dart';

import 'auth_gate.dart';
import 'providers/note_provider.dart';

class MyApp extends StatelessWidget {
  const MyApp({super.key, required this.clientId});

  final String clientId;

  @override
  Widget build(BuildContext context) {
    return ChangeNotifierProvider(
      create: (context) => NoteProvider()..fetchNotes(),
      child: MaterialApp(
        theme: ThemeData(
          colorScheme: ColorScheme.fromSeed(seedColor: Colors.deepPurple),
        ),
        home: AuthGate(clientId: clientId),
      ),
    );
  }
}
